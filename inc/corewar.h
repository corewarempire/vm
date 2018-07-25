/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/07/25 16:18:21 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h> // temp
# include <string.h> // temp
# include "op.h"

# define BUFF_SIZE 4
# define MEM_MOD(x) ((x) % MEM_SIZE)

typedef struct	s_process
{
	struct s_process	*next;						//Prochain processus..
	int					r[REG_NUMBER];				//registre
	int					id;							//Correspond au registre r1
	int					id_player;					//Joueur possedant le processus
	int					carry;						//carry du processus
	int					exec_cycle;					//cycle a effectue avant une operation
	int					op_code;					//Operation courante
	int					last_live;					//Dernier cycle live
	unsigned int		id_process;					//id du processus
	unsigned int		pc;							//index dans la ram
}				t_process;

typedef struct	s_lst_process
{
	t_process	*process;							//Liste des processus
	int			len;								//Nombre de processus instancier
}				t_lst_process;

typedef struct		s_champ
{
	struct s_champ	*next;
	int				player_id;
	int				fd;
	char			*name;
	char			*comment;
}					t_champ;

typedef struct		s_board
{
	t_lst_process	*lst_process;
	t_champ			*first_champ;					//list chainee
	int				player_id;						//ids par defaut < 0 (vm zaz)
	unsigned int	champions_count;
	unsigned int	cycle_to_die;					// CYCLE_TO_DIE
	unsigned int	cycle;							// Numero du cycle
	unsigned int	id_process;						// ID processus track
	unsigned int	last_live;
	unsigned int	last_check_purge;
	unsigned char	*ram;							// memory
	char			*opt_list;						// -dump etc
	int				dump;
}					t_board;

typedef struct		s_op
{
	char			*name;							//Name
	int				argc;							//Nombre d'argument
	int				argv[3];						//Decomposition des arguments
	int				op_code;						//Valeur de l'opcode
	int				cycles;							//duree d'execution
	char			*lname;							//Long name?
	int				octal;							//format
	int				carry;							//modifie le carry
}					t_op;

static const t_op	op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
};

/*
** process
*/

void			set_ramvalue(t_board *bd, unsigned int pc, unsigned int value);
t_lst_process	*init_list_process(void);
t_process		*add_process(t_lst_process *lst, unsigned int id_process, int r1, unsigned int pc);
int				init_process(t_board *board);
void			loop_process(t_board *board);
int				check_instruction(t_board *bd, t_process *proc);
int				get_params(t_board *bd, t_process *proc, unsigned int *pc, int data[2]);
void			purge_process(t_board *bd);

/*
** Game
*/

void			play(t_board *board);
void			add(t_board *board, t_process *process);
void			aff(t_board *board, t_process *process);
void			and(t_board *board, t_process *process);
void			frk(t_board *board, t_process *process);
void			ld(t_board *board, t_process *process);
void			ldi(t_board *board, t_process *process);
void			lfork(t_board *board, t_process *process);
void			live(t_board *board, t_process *process);
void			lld(t_board *board, t_process *process);
void			lldi(t_board *board, t_process *process);
void			or(t_board *board, t_process *process);
void			st(t_board *board, t_process *process);
void			sti(t_board *board, t_process *process);
void			sub(t_board *board, t_process *process);
void			xor(t_board *board, t_process *process);
void			zjmp(t_board *board, t_process *process);

/*
** util
*/

unsigned int	ocp_first(unsigned char c);
unsigned int	ocp_scd(unsigned char c);
unsigned int	ocp_third(unsigned char c);
int				get_dir4(t_board *bd, unsigned int pos);
short			get_dir2(t_board *bd, unsigned int pos);
int				get_indir(t_board *bd, t_process *proc, unsigned int pos);
int				get_long_indir(t_board *bd, t_process *proc, unsigned int pos);
int 			get_reg(t_process *proc, unsigned int index);


t_board 		*init_board_data(t_board *bd, char **argv);
t_board 		*collect_inputs(char **argv, int argc, t_board *bd);
void 			init_f(void (*f[17])(t_board *b, int player));
void			ft_error(int id);
void			insert_instructions(t_board *board);
void			print_memory(t_board *bd);
void			print_champ_lst(t_board *bd);

/*
 * LIBRARY FILES
 */

int				ft_atoi_base(const char *str, int base);
int				ft_onlydigit(char *str);
int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
int				pos_str_tab(char *haystack, char **needle);
char			*ft_retcmd(char *str);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_itoa_hex_byte(int value, int upper);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				get_next_line(const int fd, char **line);
void			ft_error(int n);
void			ft_puttable(char *tab);
char			*ft_strcat(char *dest, const char *src);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_chardup(char c);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
int				pos_in_str(char c, char *str);
char			*ft_strcpy(char *dest, const char *str);
void			ft_putstr(char const *s);
int				ft_strcmp(const char *tab, const char *tab2);
char			*ft_strdup(const char *s);
void			*ft_memalloc(size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strlen(const char *src);
void			ft_putnbr(int n);
unsigned char	*ft_memalloc_c(size_t size, char c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base, int upper);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_f(char const *s1, char const *s2, int j);

#endif

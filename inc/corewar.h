/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/07/20 01:48:35 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# define BUFF_SIZE 4

typedef struct		s_proc
{
	int				pos;
	int				carry;
	int				*reg[REG_NUMBER];
	struct s_proc	*next;
}					t_process;

typedef struct		s_champ
{
	char			*name;
	char			*comment;
	int				player_id;
	int				fd;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_board
{
	unsigned char	*ram;							// memory
	char			*opt_list;						// -dump etc
	t_champ			*first_champ;					//list chainee
	int				player_id;						//ids par defaut < 0 (vm zaz)
	int				champions_count;
}					t_board;


t_board 		*init_board_data(t_board *bd, char **argv);
t_board 		*collect_inputs(char **argv, t_board *bd);
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

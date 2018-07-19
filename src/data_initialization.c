// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
// /*   Updated: 2018/07/16 17:11:35 by adhondt          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../inc/corewar.h"

// void            init_f(void (*f[17])(t_board *b, int player))
// {
//   // f[0] = cmd_live;
// 	f[1] = cmd_ld;
// 	f[2] = cmd_st;
// 	f[3] = cmd_add;
// 	f[4] = cmd_sub;
// 	f[5] = cmd_and;
// 	f[6] = cmd_or;
// 	f[7] = cmd_xor;
// 	f[8] = cmd_zjmp;
// 	f[9] = cmd_ldi;
// 	f[10] = cmd_sti;
// 	f[11] = cmd_fork;
// 	f[12] = cmd_lld;
// 	f[13] = cmd_lldi;
// 	f[14] = cmd_lfork;
// 	f[15] = cmd_aff;
// }

// void			insert_instructions(t_board *board)
// {
//     int     i;
//     char    str[1];
//     int     ret;
//     char    *tp;

//     i = 0;
//     lseek(board->p1_fd, 2192, SEEK_SET);
//     while ((ret = read(board->p1_fd, str, 1) > 0))
//     {
//         ft_memcpy(((board->mem_board) + i),
//             ft_itoa_hex_byte((unsigned char)str[0], 0), 2);
//         i+= 2;
//     }
//     i = MEM_SIZE / 2;
//     lseek(board->p2_fd, 2192, SEEK_SET);
//     while ((ret = read(board->p2_fd, str, 1) > 0))
//     {
//         ft_memcpy(((board->mem_board) + i),
//             ft_itoa_hex_byte((unsigned char)str[0], 0), 2);
//         i+= 2;
//     }
// }

// void       init_name_comm(int fd, void **magic_number, char **name, char **comm)
// {
//     char    str[PROG_NAME_LENGTH + 1];
//     char    comment[COMMENT_LENGTH + 1];
//     /*
//     *magic_number = ft_memalloc(4);
//     // comparer le magic N avec celui de la VM
//     read(fd, *magic_number, 4);
//     read(fd, str, PROG_NAME_LENGTH);
//     str[ft_strlen(str) < PROG_NAME_LENGTH ?
//     ft_strlen(str) : PROG_NAME_LENGTH] = '\0';
//     */lseek(fd, PROG_NAME_LENGTH + 4 + 8, SEEK_SET);
//         // + 4 : magicN, +8....? a quoi correspond les 2 octects avant comment
//     read(fd, comment, COMMENT_LENGTH);
//      comment[ft_strlen(comment) < COMMENT_LENGTH ?
//     ft_strlen(comment) : COMMENT_LENGTH] = '\0';
//     *name = ft_strdup(str);
//     *comm = ft_strdup(comment);
// }

// t_board    *init_board_data(t_board *board, char **argv)
// {
//     if (!(board = (t_board *)malloc(sizeof(t_board))))
//         ft_error(0);
//     board->mem_board = ft_memalloc_c(MEM_SIZE, '0');
//     board->p1_fd = open(argv[1], O_RDONLY);
//     board->p2_fd = open(argv[2], O_RDONLY);
//     if (board->p1_fd == -1 || board->p2_fd == -1)
//         ft_error(1);
//     init_name_comm(board->p1_fd, &(board->p1_magic_n),
//     &(board->p1_name), &(board->p1_comm));
//     init_name_comm(board->p2_fd, &(board->p2_magic_n),
//     &(board->p2_name), &(board->p2_comm));
//     board->p1_i = 0;
//     board->p2_i = MEM_SIZE / 2;
//     return (board);
// }

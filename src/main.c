/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/07/20 01:46:51 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_board *init_board_data(t_board *bd, char **argv)
{ 
    int i;

    i = 0;
    if (!(bd = (t_board *)malloc(sizeof(t_board))))
        ft_error(0);
    bd->ram = ft_memalloc_c(MEM_SIZE, 0);
    bd->champions_count = 0;
    while (argv[++i])
        if (ft_strlen(argv[i]) >= 5 &&
                ft_strcmp(argv[i] + ft_strlen(argv[i]) - 4, ".cor") == 0)
            bd->champions_count++;
    if (bd->champions_count > 4 || bd->champions_count < 1)
        ft_error(1);
    bd->opt_list = NULL;
    bd->first_champ = NULL;
    bd->player_id = 0;
    return (bd);
}

int	main(int argc, char **argv)
{
    t_board  *board;

    if (argc < 2)
        ft_error(1);
    board = init_board_data(board, argv);
    collect_inputs(argv, board);
    insert_instructions(board);
    // execute_war(board);
    print_champ_lst(board);
    print_memory(board);
    return (0);
}

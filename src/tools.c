/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:06:53 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 13:26:26 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void    ft_usage(void)
{
    ft_putstr("./corewar [-d, -n] <champion1.cor> <...> [4 .cor maximum]\n");
    ft_putstr("-d N : Dump Memory at N cycles\n");
    ft_putstr("-n N <champ.cor> : Attribute N as player number to champ.cor\n");
}

void    ft_error(int id)
{
    if (id == 0)
        ft_putstr_fd("ERROR: Memory Allocation failed\n", 2);
    else if (id == 1)
    {
        ft_putstr_fd("ERROR: Bad arguments.\n", 2);
        ft_usage();
    }
    else if (id == 2)
        ft_putstr_fd("ERROR: Wrong Magic number\n", 2);
    exit(0);
}

void    print_memory(t_board *bd)
{
    int i;
    unsigned char j;

    i = 0;
    while (i != MEM_SIZE)
    {
        j = (bd->ram[i] / 16) + 48;
        j > '9' ? ft_putchar(j + 39) : ft_putchar(j);
        j = (bd->ram[i] % 16) + 48;
        j > '9' ? ft_putchar(j + 39) : ft_putchar(j);
        ft_putchar(' ');
        i++;
    }
}

void   print_champ_lst(t_board *bd)
{
    t_champ *tmp;

    tmp = bd->first_champ;
    while (tmp)
    {
        printf("\nChamp name:%s|\nChamp p_id:%d|\n", tmp->name, tmp->player_id);
        printf("Champ fd:%d|\nChamp comment :%s|\n", tmp->fd, tmp->comment);
        tmp = tmp->next;
    }
}
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

void        add_champ_to_lst(t_board *bd, t_champ *champ)
{
    t_champ *tmp;

    tmp = bd->first_champ;
    if (!bd->first_champ)
        bd->first_champ = champ;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = champ;
    }
}

t_champ     *collect_champion_data(t_board *bd, int fd, t_champ *champ)
{
    unsigned char   magic[5];
    char            str[PROG_NAME_LENGTH + 1];
    char            comment[COMMENT_LENGTH + 1];

    if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
        ft_error(0);
    read(fd, magic, 4);
    if (!((int)magic[1] == 234 && (int)magic[2] == 131 && (int)magic[3] == 243))
        ft_error(2);
    read(fd, str, PROG_NAME_LENGTH);
    str[PROG_NAME_LENGTH] = '\0';
    champ->name = ft_strdup(str);
    lseek(fd, PROG_NAME_LENGTH + 4 + 8, SEEK_SET);
    read(fd, comment, COMMENT_LENGTH);
    comment[COMMENT_LENGTH] = '\0';
    champ->comment = ft_strdup(comment);
    champ->fd = fd;
    champ->next = NULL;
    return (champ);
}

static void     attribute_id(t_board *bd, t_champ *champ, int op, char **argv)
{
    // A faire : Gerer l'attribution d'ID (doublons !)
    // Actuellement attribution decroissante depuis 0, comme zaz.
    champ->player_id = --bd->player_id;
}
static int      open_champ(t_board *bd, char **argv, int i, int op)
{
    int fd;
    t_champ *champ;

    if (ft_strlen(argv[i + op]) <= 4 || !ft_strcmp(argv[i + op]
        + ft_strlen(argv[i + op] - 4), ".cor"))
        return (0);
    if ((fd = open(argv[i + op], O_RDONLY)) == -1)
        ft_error(1);
    champ = collect_champion_data(bd, fd, champ);
    attribute_id(bd, champ, op, argv);
    add_champ_to_lst(bd, champ);
    return (1);
}

static int      get_dump(t_board *bd, char **argv, int i)
{
    // A faire : Stocker si memory dump
    return (0);
}

static void     check_arg(char **argv, int *i, t_board *bd)
{
    static char *opt_list[3] = {"-n", "-dump"};
    int         n;

    n = 3;
    if (argv[*i][0] == '-' && (n = pos_str_tab(argv[*i], opt_list)) == -1)
        ft_error(1);
    else if (n == 0)
    {
        if (!argv[*i + 1] || !argv[*i + 2] || !ft_onlydigit(argv[*i + 1]) ||
                !open_champ(bd, argv, *i, 2))
            ft_error(1);
        *i += 2;
    }
    else if (n == 1)
    {
        if (!argv[*i + 1] || !ft_onlydigit(argv[*i + 1]) ||
            !get_dump(bd, argv, *i))
            ft_error(1);
    }
    else
        open_champ(bd, argv, *i, 0);
}

t_board         *collect_inputs(char **argv, t_board *bd)
{
    int i;

    i = 0;
    while (argv[++i])
            check_arg(argv, &i, bd);
    return (bd);
}
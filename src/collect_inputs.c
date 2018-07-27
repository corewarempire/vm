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

int     collect_champion_data(t_board *bd, int fd, t_champ **champ)
{
    unsigned char   magic[5];
    char            str[PROG_NAME_LENGTH + 1];
    char            comment[COMMENT_LENGTH + 1];

    if (!((*champ) = (t_champ *)malloc(sizeof(t_champ))))
        return (ft_error(1, 0));
    if (read(fd, magic, 4) == -1)
        return (ft_error(3, 1));
    if (!((int)magic[1] == 234 && (int)magic[2] == 131 && (int)magic[3] == 243))
        return (ft_error(3, 0));
    if (read(fd, str, PROG_NAME_LENGTH) == -1)
        return (ft_error(3, 1));
    str[PROG_NAME_LENGTH] = '\0';
    if (!((*champ)->name = ft_strdup(str)))
        return (ft_error(1, 0));
    lseek(fd, PROG_NAME_LENGTH + 4 + 8, SEEK_SET);
    if (read(fd, comment, COMMENT_LENGTH) == -1)
        return (ft_error(3, 1));
    comment[COMMENT_LENGTH] = '\0';
    if (!((*champ)->comment = ft_strdup(comment)))
        return (ft_error(1, 0));
    (*champ)->fd = fd;
    (*champ)->next = NULL;
	(*champ)->process_count = 1;
    return (1);
}
int             get_first_number(t_board *bd, int i)
{
    t_champ *tmp;

    tmp  = bd->first_champ;
    while (tmp)
        if (i == tmp->player_id && (i += 1))
            tmp = bd->first_champ;
        else
            tmp = tmp->next;
    return (i);
}

static int     attribute_id(t_board *bd, t_champ *champ, int t[2], char **argv)
{
    if (!t[1])
        champ->player_id = get_first_number(bd, 1);
    else
    {
        if (ft_atoi(argv[t[0] + 1]) < -16 || ft_atoi(argv[t[0] + 1]) > 16 )
            return(ft_error(2, 0));
        champ->player_id = get_first_number(bd, ft_atoi(argv[t[0] + 1]));
    }
    return (1);
}

static int      open_champ(t_board *bd, char **argv, int i, int op)
{
    int fd;
    t_champ *champ;

    if (ft_strlen(argv[i + op]) <= 4 || !ft_strcmp(argv[i + op]
        + ft_strlen(argv[i + op] - 4), ".cor"))
        return (ft_error(3, 0));
    if ((fd = open(argv[i + op], O_RDONLY)) == -1)
        return (ft_error(3, 1));
    if (!(collect_champion_data(bd, fd, &champ)))
        return (0);
    if (!(attribute_id(bd, champ, (int[2]){i, op}, argv)))
        return (0);
    add_champ_to_lst(bd, champ);
    return (1);
}

static int      dump(t_board *bd, char **argv, int i)
{
    bd->dump = ft_atoi(argv[i + 1]);
    if (bd->dump < 0)
        return (0);
    return (1);
}

static int     get_verbose(t_board *bd, char *arg)
{
    int level;

    level = ft_atoi(arg);
    if (level < 0 || level > 4)
        return (0);
    bd->verbose[level] = 1;
    return (1);
}

static int      check_arg_ii(t_board *bd, char **argv, int *i)
{

    return (0);
}

static int      check_arg(t_board *bd, char **argv, int *i)
{
    static char *opt_list[3] = {"-n", "-d", "-v"};
    int         n;

    n = 4;
    if (argv[*i][0] == '-' && (n = pos_str_tab(argv[*i], opt_list)) == -1)
        return (ft_error(2, 0));
    else if (n == 0)
    {
        if (!argv[*i + 1] || !argv[*i + 2] || !ft_isnumber(argv[*i + 1]))
            return (ft_error(2, 0));
        if (!open_champ(bd, argv, *i, 2))
            return (0);
        *i += 2;
    }
    else if (n == 1)
    {
        if (!argv[*i + 1] || !ft_isnumber(argv[*i + 1]) || !dump(bd, argv, *i))
            return (ft_error(2, 0));
        *i += 1;
    }
    else if (n == 2)
        if (!argv[*i + 1] || !ft_isnumber(argv[*i +1]) ||
                !get_verbose(bd, argv[*i + 1]))
            return (ft_error(2, 0));
        else
            *i += 1;
    else if (!open_champ(bd, argv, *i, 0))
        return (0);
    return (1);
}

t_board         *collect_inputs(char **argv, int argc, t_board *bd)
{
    int i;

    i = 1;
    while (argv[i] && i < argc)
    {
        if (!(check_arg(bd, argv, &i)))
            return (NULL);
        i++;
    }
        return (bd);
}
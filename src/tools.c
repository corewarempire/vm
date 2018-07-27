#include "../inc/corewar.h"

void    ft_usage(void)
{
    ft_putstr("./corewar [-d, -n, -v] <champion1.cor> <..> [1 - 4 .cor]\n");
    ft_putstr("-d N : Dump Memory at N cycles [0 - ...]\n");
    ft_putstr("-n N <champ.cor> : Attribute N as player number to champ.cor\n");
    ft_putstr("-v N : Display level [1 - 4]:\n\t1:Only Winner\n\t1:Cycles");
    ft_putstr("\n\t2: Operations \n\t3:Memory each CYCLE_TO_DEATH\n");
}

int    ft_error(int id, int errn)
{
    if (id == 1)
    {
        ft_putstr_fd("ERROR: Memory Allocation failed.\n\n", 2);
    }
    else if (id == 2)
    {
        ft_putstr_fd("ERROR: Wrong flag usage.\n\n", 2);
    }
        else if (id == 3)
    {
        ft_putstr_fd("ERROR : Wrong [champion].cor file", 2);
        if (errn == 1)
            ft_put3str(" -> ", strerror(errno), ".\n\n");
        else
            ft_putstr(".\n\n");
    }        
    else if (id == 4 || id == 5)
    {
        id == 4 ? ft_putstr_fd("ERROR: Bad dump (-d) data.\n\n", 2) :
        ft_putstr_fd("ERROR:Bad verbose (-v) data.\n\n", 2);
    }
    else if (id == 6)
    {
        ft_putstr_fd("ERROR: Wrong [champion].cor count [1 - 4]\n\n", 2);
    }
    ft_usage();
    return (0);
}

void    print_memory(t_board *bd)
{
    int i;
    unsigned char j;

    i = 0;
    if (bd->cycle == bd->dump)
    {
        print_champ_lst(bd);
        ft_putchar('\n');
    }
    while (i != MEM_SIZE)
    {
        j = (bd->ram[i] / 16) + 48;        
j > '0' ? ft_putstr("\033[0;31m") : 0;
        j > '9' ? ft_putchar(j + 39) : ft_putchar(j);
        j = (bd->ram[i] % 16) + 48;
j > '0' ? ft_putstr("\033[0;31m") : 0;
        j > '9' ? ft_putchar(j + 39) : ft_putchar(j);
        ft_putchar(' ');
        i++;
ft_putstr("\033[0m");
    }
}

void   print_champ_lst(t_board *bd)
{
    t_champ *tmp;

    tmp = bd->first_champ;
    while (tmp)
    {
        ft_putstr("Champion name: [");
        ft_putstr(tmp->name);
        ft_putstr("] Player id: [");
        ft_putnbr(tmp->player_id);
        ft_putstr("] \n");
        tmp = tmp->next;
    }
    ft_putstr("Nombre de cycles écoulés: ");
    ft_putnbr(bd->cycle);
    ft_putstr("\n");
}
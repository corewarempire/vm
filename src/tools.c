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
        printf("error name:%s|\n", strerror(errno));
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
//    printf("---TOOLS DISPLAY ---\nCycle:%d, Cycle to die:%d, NBR_LIVE:%d, NBR_CHECK:%d\n---END OF---\n", bd->cycle, bd->cycle_to_die, bd->total_cycle_live, bd->check_nbr);
    ft_putstr("Nombre de cycles écoulés: ");
    ft_putnbr(bd->cycle);
    ft_putstr("\n");
}
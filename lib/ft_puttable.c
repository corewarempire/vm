#include "../inc/corewar.h"

void    ft_puttable(char *tab)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i != MEM_SIZE)
    {
        ft_putchar(tab[i]);
        if (j == 2)
        {
            ft_putchar(' ');
            j = 0;
        }
        j++;
        i++;
    }
}
#include "../inc/corewar.h"

void       insert_code(t_board *bd, int pos)
{
    t_champ         *tmp;
    unsigned char   *str;

    str = (unsigned char *)malloc(sizeof(unsigned char));
    tmp = bd->first_champ;
    while (tmp->next && tmp->next->fd != 0)
        tmp = tmp->next;
    lseek(tmp->fd, 2192, SEEK_SET);
    while ((read(tmp->fd, str, 1) > 0))
    {
        bd->ram[pos] = (unsigned char)str[0];
        pos++;
    }
    close(tmp->fd);
    tmp->fd = 0;
}


void    insert_instructions(t_board *bd)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < bd->champions_count)
    {
        insert_code(bd, (j * i++));
        j = MEM_SIZE / bd->champions_count;
    }
}
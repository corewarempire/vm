#include "../inc/corewar.h"

int       insert_code(t_board *bd, int pos)
{
    t_champ         *tmp;
    unsigned char   *str;

    tmp = bd->first_champ;
    while (tmp->next && tmp->next->fd != 0)
        tmp = tmp->next;        
    lseek(tmp->fd, 2192, SEEK_SET); //protegerer lseek?
    while ((read(tmp->fd, str, 1) > 0))
    {
        bd->ram[pos] = (unsigned char)str[0];
        pos++;
    }
    close(tmp->fd);
    tmp->fd = 0;
    return (1);
}

int    insert_instructions(t_board *bd)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < bd->champions_count)
    {
        if (!insert_code(bd, (j * i++)))
            return (ft_error(3, 1)); 
            j = MEM_SIZE / bd->champions_count;
    }    
    return (1);
}

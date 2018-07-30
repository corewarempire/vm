#include "corewar.h"

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

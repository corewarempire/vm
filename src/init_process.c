#include "corewar.h"

int		init_process(t_board *bd)
{
	int	i;
	int	pc;
	t_process		*proc;
	t_champ			*champ;

	i = 0;
	pc = 0;
	champ = bd->first_champ;
	if (!(bd->lst_process = init_list_process()))
		return (0);
	while (i < bd->champions_count)
	{
		if (!(proc = add_process(bd->lst_process, bd->id_process++, champ->player_id, pc)))
			return (0);
		proc->last_live = bd->cycle;
		pc += MEM_SIZE / bd->champions_count;
		i++;
		champ = champ->next;
	}
	return (1);
}
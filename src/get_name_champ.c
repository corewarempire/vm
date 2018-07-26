#include "corewar.h"

char	*get_name_champ(t_board *bd, int id)
{
	t_champ *champ;

	champ = bd->champ;
	while (champ)
	{
		if (champ->player_id == id)
			return (champ->name);
		champ = champ->next;
	}
	return (0);
}

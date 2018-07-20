#include "corewar.h"

int		init_process(t_board *board)
{
	int	i;
	int	pc;
	t_process		*proc;
	t_champ			*champ;

	i = 0;
	pc = 0;
	champ = board->first_champ;
	if (!(board->lst_process = init_list_process()))
		return (0);
//	while (i < board->champions_count)
//	{
		printf("TETE DU PROCEi-SSUS %u / / p_id:%d \n", pc, champ->player_id);
		i = champ->player_id;
		if (!(proc = add_process(board->lst_process, i, pc)))
			return (0);
		pc += MEM_SIZE / board->champions_count;
//		i++;
//	}
	return (1);
}
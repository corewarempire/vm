#include "corewar.h"

int		init_process(t_board *board)
{
	unsigned int	i;
	unsigned int	pc;
	t_process		*proc;

	i = 0;
	pc = 0;
	if (!(board->lst_process = init_list_process()))
		return (0);
//	while (i < board->champions_count)
//	{
		printf("TETE DU PROCESSUS %u\n", pc);
		if (!(proc = add_process(board->lst_process, i, pc)))
			return (0);
		pc += MEM_SIZE / board->champions_count;
//		i++;
//	}
	return (1);
}
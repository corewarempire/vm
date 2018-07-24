#include "corewar.h"

void	run(t_board *bd)
{
	unsigned int	last_check_purge;
	t_process		*proc;

	write(1, "START\n", 6);
	bd->last_check_purge = 0;
	proc = bd->lst_process->process;
	while (bd->lst_process && bd->cycle < 1756)
	{
		while (proc)
		{
			check_instruction(bd, proc);
			if (bd->last_check_purge == bd->cycle - bd->cycle_to_die)
			{
				purge_process(bd);
				bd->last_check_purge = bd->cycle;
			}
			proc = proc->next;
		}
		bd->cycle++;
		if (!bd->lst_process->process)
			break ;
		proc = bd->lst_process->process;
	}
	printf("Cycle atteint %d\n", bd->cycle);
}

void	play(t_board *board)
{
	if (board->champions_count < 1)
		return ;
	if (!init_process(board))
		return ;
	board->cycle_to_die = CYCLE_TO_DIE;
	run(board);
}

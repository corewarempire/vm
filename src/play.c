#include "corewar.h"

void	run(t_board *bd)
{
	t_process *proc;

	// write(1, "START\n", 6);
	proc = bd->lst_process->process;
	while (bd->lst_process->len)
	{
		check_instruction(bd, proc);
		purge_process(bd);
		if (!bd->lst_process->process)
			break ;
		bd->cycle++;
		proc = (proc->next) ? proc->next : bd->lst_process->process;
	}
	// write(1, "END\n", 4);
}

void	play(t_board *board)
{
	printf("%d\n", board->champions_count);
	if (board->champions_count < 1)
		return ;
	if (!init_process(board))
		return ;
	board->cycle_to_die = CYCLE_TO_DIE;
	run(board);
}

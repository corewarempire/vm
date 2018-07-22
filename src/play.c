#include "corewar.h"

void	run(t_board *board)
{
	t_process *proc;

	// write(1, "START\n", 6);
	proc = board->lst_process->process;
	int i = 0;
	while (board->lst_process->len && i < 1000)
	{
		check_instruction(board, proc);
		proc = (proc->next) ? proc->next : board->lst_process->process;
		i++;
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
#include "corewar.h"

int		check_process_status(t_board *bd)
{
		bd->check_nbr++;
		purge_process(bd);
		bd->last_check_purge = bd->cycle;
		if (bd->total_cycle_live >= NBR_LIVE || bd->check_nbr == MAX_CHECKS)
		{
			bd->cycle_to_die -= CYCLE_DELTA;
			bd->check_nbr = 0;
		}
		bd->total_cycle_live = 0;
	return ((bd->lst_process->process) != NULL && bd->cycle_to_die > 0);
}

void	run(t_board *bd)
{
	unsigned int	last_check_purge;
	t_process		*proc;

	// write(1, "START\n", 6);
	bd->last_check_purge = 0;
	proc = bd->lst_process->process;
	while (bd->lst_process && bd->cycle < bd->dump)
	{
		while (proc)
		{
			check_instruction(bd, proc);
			printf("Process:[%d], PC:[%d] Function:[%s], ", proc->id_player, proc->pc, op_tab[proc->op_code].name);
			printf("Cycle:%d, Cycle to die:%d, NBR_LIVE:%d, NBR_CHECK:%d\n", bd->cycle, bd->cycle_to_die, bd->total_cycle_live, bd->check_nbr);
			proc = proc->next;
		}
		if ((bd->last_check_purge == bd->cycle - bd->cycle_to_die && 
				!check_process_status(bd)) || (bd->cycle_to_die <= 0))
			break ;
		bd->cycle++;
		proc = bd->lst_process->process;
	}
	//printf("Cycle atteint %d\n", bd->cycle);
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

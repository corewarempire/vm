#include "corewar.h"

void	live(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	proc->pc++;
	val = get_params(bd, proc, &proc->pc, (int[3]){T_DIR, 0, 0});
	proc->last_live = bd->cycle;
	bd->total_cycle_live += 1;
	bd->last_live = val;
	// checker si val correspond bien a un joueur
}

#include "corewar.h"

void	live(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	proc->pc++;
	if (proc->id_player == -1)
		printf("live:\n");
	val = get_params(bd, proc, &proc->pc, (int[3]){T_DIR, 0, 0});
	proc->last_live = bd->cycle;
	bd->total_cycle_live += 1;
	bd->last_live = val;
	// printf("Joueur en vie %d Owner %d\n", val, proc->id_player);
}
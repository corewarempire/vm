#include "corewar.h"

void	live(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	proc->pc++;
	// printf("live\n");
	val = get_params(bd, proc, &proc->pc, (int[3]){T_DIR, 0, 0});
	proc->last_live = bd->cycle;
	// printf("Joueur en vie %d\n", val);
}
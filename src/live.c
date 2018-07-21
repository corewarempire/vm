#include "corewar.h"

void	live(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	proc->pc++;
	val = get_params(bd, proc, &proc->pc, {T_DIR, 0});
	proc->last_live = bd->cycle;
	proc->pc++;
	printf("Joueur en vie %d\n", val);
}
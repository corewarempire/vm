#include "corewar.h"

void	lfork(t_board *bd, t_process *proc)
{
	t_process	*new;
	int			newpc;

	proc->pc++;
	// printf("lfork\n");
	newpc = get_params(bd, proc, &proc->pc, (int[3]){T_DIR, 1, 1});
	if (!(new = add_process(bd->lst_process, proc->id_player, newpc)))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
	*new = *proc;
	new->pc = newpc;
}
#include "corewar.h"

void	frk(t_board *bd, t_process *proc)
{
	t_process	*new;
	int			newpc;

	proc->pc++;
	newpc = get_params(bd, proc, &proc->pc, (int[2]){T_DIR, 1});
	if (!(new = add_process(bd->lst_process, proc->id_player, (newpc % IDX_MOD))))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
}
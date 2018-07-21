#include "corewar.h"

void	frk(t_board *bd, t_process *proc)
{
	t_process	*new;
	int			newpc;

	proc->pc++;
	newpc = get_params(bd, proc, &proc->pc, {T_DIR, 1});
	if (!(new = add_process(board->lst_process, proc->player_id, (newpc % IDX_MOD))))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
}
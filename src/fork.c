#include "corewar.h"

void	frk(t_board *bd, t_process *proc)
{
	t_process	*new;
	int			newpc;

	proc->pc++;
	if (proc->id_player == -1)
		printf("processsus forked\n");
	newpc = get_params(bd, proc, &proc->pc, (int[3]){DIR_CODE, 1, 0});
	// printf("newpc %d\n", newpc);
	if (!(new = add_process(bd->lst_process, proc->id_player, (newpc))))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
	// printf("NEW FORK PROCESSUS\n");
	// *new = *proc;
	// new->pc = newpc;
	//memcpy
}
#include "corewar.h"

void	lfork(t_board *bd, t_process *proc)
{
	t_process		*new;
	unsigned int	pc;
	int				newpc;

	pc = proc->pc + 1;
	printf("lfork\n");
	newpc = get_params(bd, proc, &pc, (int[3]){DIR_CODE, 1, 1});
	if (!(new = add_process(bd->lst_process, bd->id_process++, proc->id_player, (newpc))))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
	new->pc = MEM_MOD(newpc);
	proc->pc = MEM_MOD(pc);
	update_process_count(bd, proc->id_player, 1);
}

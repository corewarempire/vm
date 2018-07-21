#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val0;

	proc->pc++;
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	ocp[2] = ocp_third(bd->ram[proc->pc++]);
	val0 = get_params(bd, proc, &pc, (int[2]){ocp[0], 0});
	val1 = get_params(bd, proc, &pc, (int[2]){ocp[1], 1})
			+ get_params(bd, proc, &pc, (int[2]){ocp[2], 1});
	proc->carry = (!val1) ? 1 : 0;
	set_ramvalue(bd, proc->pc + val1, val0);
}
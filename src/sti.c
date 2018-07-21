#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val0;

	pc = proc->pc;
	ocp[0] = ocp_first(bd, pc);
	ocp[1] = ocp_scd(bd, pc);
	ocp[2] = ocp_third(bd, pc++);
	val0 = get_params(bd, proc, &pc, {ocp[0], 0});
	val1 = get_params(bd, proc, &pc, {ocp[1], 1}) + get_params(bd, proc, &pc, {ocp[2], 1});
	proc->carry = (!val1) ? 1 : 0;
	set_ramvalue(bd, proc->pc + val1, val0);
}
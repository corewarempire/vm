#include "corewar.h"

void	lld(t_board *bd, t_process *proc)
{
	unsigned char	ocp;
	int				val1;
	int				val2;

	proc->pc++;
	ocp = ocp_first(bd->ram[MEN_NOD(proc->pc++)]);
	if (!(val1 = get_params(bd, proc, &proc->pc, {ocp, 1})))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = val1;
	proc->pc++;
}
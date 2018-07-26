#include "corewar.h"

void	lld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val1;
	unsigned char	ocp;

	pc = proc->pc;
	pc++;
	ocp = ocp_first(bd->ram[MEM_MOD(pc)]);
	pc++;
	if (!(val1 = get_params(bd, proc, &pc, (int[3]){ocp, 0, 1})))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[bd->ram[MEM_MOD(pc)] - 1] = val1;
	proc->pc = pc + 1;
}

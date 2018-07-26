#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				ocp;
	int				first_reg;
	int				value;

	pc = proc->pc + 1;
	ocp = ocp_scd(bd->ram[MEM_MOD(pc)]);
	pc++;
	first_reg = get_params(bd, proc, &pc, (int[3]){T_REG, 0, 0});
	value = get_params(bd, proc, &pc, (int[3]){ocp, 0, 0});
	proc->carry = (!first_reg) ? 1 : 0;
	if (ocp == IND_CODE)
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), first_reg);
	else if (ocp == REG_CODE)
		proc->r[value - 1] = first_reg;
	proc->pc = (ocp == IND_CODE) ? 5 : 4;
}
#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	int	octal;
	int first_reg;
	int value;

	octal = ocp_scd(bd->ram[proc->pc + 1]);
	first_reg = get_reg(proc, proc->pc + 2);
	value = (octal & T_IND) ? get_indir(bd, proc->pc + 3) : get_reg(proc, proc->pc + 3);
	proc->carry = (!first_reg) ? 1 : 0;
	if (octal & T_REG)
		proc->r[value - 1] = first_reg;
	else
	{
		
	}
}
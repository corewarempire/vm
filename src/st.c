#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned int	octal;
	unsigned int	reg;
	unsigned int	offset;
	int				val1;

	pc = proc->pc;
	octal = ocp_scd(bd->ram[MEM_MOD(pc + 1)]);
	reg = bd->ram[MEM_MOD(pc + 2)];
	offset = octal == REG_CODE ? 4 : 5;
	reg = proc->r[reg - 1];
	if (octal == REG_CODE && (val1 = bd->ram[MEM_MOD(pc + 3)]))
		proc->r[val1 - 1] = reg;
	else
	{
		val1 = (short)get_dir(bd, pc + 3, 1);
		set_ramvalue(bd, pc + (val1 % IDX_MOD), reg);
	}
	process->pc += offset;
}

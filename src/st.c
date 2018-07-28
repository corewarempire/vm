#include "corewar.h"

void	verbosity(int ocp, t_process *proc, int value, int first_reg)
{
	ocp == IND_CODE ? ft_putstrnbrstr(" at ", (proc->pc + (value % IDX_MOD)),
	" = ") : ft_putstrnbrstr(" in r", value, " = ");
	ft_putnbr(first_reg);
	ft_putstr("\n\n");
}

void	st(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned int	ocp;
	unsigned int	value_reg;
	unsigned int	offset;
	int				value;

	pc = proc->pc;
	printf("st:\n");
	ocp = ocp_scd(bd->ram[MEM_MOD(pc + 1)]);
	value_reg = proc->r[bd->ram[MEM_MOD(pc + 2)] - 1];
	value = (ocp == REG_CODE) ? bd->ram[MEM_MOD(pc + 3)] : get_indir(bd, proc, pc + 3);
	if (ocp == REG_CODE)
		proc->r[value - 1] = value_reg;
	else
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), value_reg);
	if (bd->verbose[1])
		verbosity(ocp, proc, value, value_reg);
	proc->pc += (ocp == IND_CODE) ? 5 : 4;
}
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
	unsigned int	first_reg;
	unsigned int	offset;
	int				value;

	pc = proc->pc + 1;
	printf("st:\n");
	ocp = ocp_scd(bd->ram[MEM_MOD(pc)]);
	pc++;
	first_reg = get_params(bd, proc, &pc, (int[3]){T_REG, 0, 0});
		if (bd->verbose[1])
	{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nSt r", bd->ram[MEM_MOD(pc - 1)]);
	}
	value = get_params(bd, proc, &pc, (int[3]){ocp, 0, 0});
	proc->carry = (!first_reg) ? 1 : 0;
	if (ocp == IND_CODE)
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), first_reg);
	else if (ocp == REG_CODE)
		proc->r[value - 1] = first_reg;
	if (bd->verbose[1])
		verbosity(ocp, proc, value, first_reg);
	proc->pc += (ocp == IND_CODE) ? 5 : 4;
}
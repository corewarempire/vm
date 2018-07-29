#include "corewar.h"

static void	verbosity(t_board *bd, t_process *proc, int data[3])
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nSt r", bd->ram[MEM_MOD(proc->pc + 2)]);
	(data[2] == REG_CODE) ? ft_putstrnbrstr("to r", data[0], "carry: X") :
	ft_putstrnbrstr("to ", data[1], "carry: X");
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
	ocp = ocp_scd(bd->ram[MEM_MOD(pc + 1)]);
	value_reg = proc->r[bd->ram[MEM_MOD(pc + 2)] - 1];
	value = (ocp == REG_CODE) ? bd->ram[MEM_MOD(pc + 3)] : get_indir(bd, pc + 3);
	if (ocp == REG_CODE)
		proc->r[value - 1] = value_reg;
	else
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), value_reg);
	if (bd->verbose[1])
		verbosity(bd, proc, (int [3]){value, value_reg, ocp});
	proc->pc += (ocp == IND_CODE) ? 5 : 4;
}
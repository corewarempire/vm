#include "corewar.h"

// {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},

static void	verbosity(t_board *bd, t_process *proc, int value, int reg)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLd ", value);
	ft_putstrnbrstr(" in r", reg, ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}

void	ld(t_board *bd, t_process *proc)
{
	int	ocp;
	int	offset;
	int	reg;
	int	value;

	ocp = ocp_first(bd->ram[MEM_MOD(proc->pc + 1)]);
	value = (ocp == IND_CODE) ? get_indir(bd, proc->pc + 2): get_dir4(bd, proc->pc + 2);
	proc->carry = (!value) ? 1 : 0;
	reg = (ocp == IND_CODE) ? bd->ram[MEM_MOD(proc->pc + 4)] : bd->ram[MEM_MOD(proc->pc + 6)];
	proc->r[reg - 1] = value;
	proc->pc += (ocp == IND_CODE) ? 5 : 7;
	if (bd->verbose[1])
		verbosity(bd, proc, value, reg);
}
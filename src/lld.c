#include "corewar.h"

static void	verbosity(t_board *bd, t_process *proc, int ocp, int val)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	if (ocp == DIR_CODE)
	{
		ft_putnbrstrnbr(proc->id_process, "\nLld ", val);
		ft_putstrnbrstr(" in r", bd->ram[MEM_MOD(proc->pc + 6)], ". Carry : ");
	}
	else
	{
		ft_putnbrstrnbr(proc->id_process, "\nLld ", get_dir2(bd, proc->pc + val));
		ft_putstrnbrstr(" in r", bd->ram[MEM_MOD(proc->pc + 4)], ". Carry : ");
	}
	ft_putnbr(proc->carry);
	ft_putstr("\n");
}

void	lld(t_board *bd, t_process *proc)
{
	int	ocp;
	int	value;

	ocp = ocp_first(bd->ram[MEM_MOD(proc->pc + 1)]);
	value = (ocp == DIR_CODE) ? get_dir4(bd, proc->pc + 2) :
	get_long_indir(bd, proc->pc + 2);
	proc->carry = (!value) ? 1 : 0;
	if (ocp == DIR_CODE)
		proc->r[bd->ram[MEM_MOD(proc->pc + 6)] - 1] = value;
	else
		proc->r[bd->ram[MEM_MOD(proc->pc + 4)] - 1] = get_dir2(bd, proc->pc + value);
	if (bd->verbose[1])
		verbosity(bd, proc, ocp, value);
	proc->pc += (ocp == DIR_CODE) ? 7 : 5;
}

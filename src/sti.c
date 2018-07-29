#include "corewar.h"

static void	verbosity(t_board *bd, t_process *proc, unsigned char *ocp, int *val)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nSti r", bd->ram[proc->pc + 2]);
	ft_putstrnbrstr(" to ", val[1], " + ");
	ft_putnbrstrnbr(val[2], " = ", val[1] + val[2]);
	ft_putstrnbrstr(" (with PC and mod at : ", (proc->pc + ((val[1] + val[2]) % IDX_MOD)), "). Carry :");
	ft_putnbr(proc->carry);
	ft_putstr(".\n\n");
}

void	sti(t_board *bd, t_process *proc)
{
	unsigned char	ocp[2];
	int				val[3];
	int				offset;

	ocp[0] = ocp_scd(bd->ram[MEM_MOD(proc->pc + 1)]);
	ocp[1] = ocp_third(bd->ram[MEM_MOD(proc->pc + 1)]);
	val[0] = proc->r[bd->ram[proc->pc + 2] - 1];
	if (ocp[0] == REG_CODE)
	{
		val[1] = proc->r[bd->ram[proc->pc + 3] - 1];
		val[2] = (ocp[1] == DIR_CODE) ? get_dir2(bd, proc->pc + 4) : proc->r[bd->ram[proc->pc + 4] - 1];
		offset = (ocp[1] == DIR_CODE) ? 6 : 5;
	}
	else
	{
		val[1] = (ocp[0] == IND_CODE) ? get_indir(bd, proc, proc->pc + 3) : get_dir2(bd, proc->pc + 3);
		if (ocp[0] == IND_CODE)
			val[1] = get_dir4(bd, proc->pc + val[1]);
		val[2] = (ocp[1] == DIR_CODE) ? get_dir2(bd, proc->pc + 5) : proc->r[bd->ram[proc->pc + 5] - 1];
		offset = (ocp[1] == DIR_CODE) ? 7 : 6;
	}
	if (bd->verbose[1])
		verbosity(bd, proc, ocp, val);
	set_ramvalue(bd, (proc->pc + ((val[1] + val[2]) % IDX_MOD)), val[0]);
	proc->pc += offset;
}

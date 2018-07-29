#include "corewar.h"

static void	verbosity(t_board *bd, t_process *proc, int *ocp, int *val)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLldi (", val[0]);
	ft_putstrnbrstr(" + ", val[1], ") -> ");
	ft_putnbr(val[0] + val[1]);
	ft_putstrnbrstr(" (with pc and mod ", proc->r[val[2] - 1], ")");
	ft_putstr(".\n\n");
}

static	int		get_value(t_board *bd, int *pc, int ocp, int flag)
{
	int res;

	if (ocp == REG_CODE)
	{
		res = bd->ram[MEM_MOD(*pc)];
		(*pc) += 1;
	}
	else if (ocp == DIR_CODE)
	{
		res = (flag) ? get_dir4(bd, *pc) : get_dir2(bd, *pc);
		(*pc) += (flag) ? 4 : 2;
	}
	else if (ocp == IND_CODE)
	{
		res = (flag) ? get_long_indir(bd, *pc) : get_dir2(bd, *pc);
		(*pc) += 2;
	}
	return (res);
}

void			lldi(t_board *bd, t_process *proc)
{
	int		ocp[3];
	int		val[3];
	int		offset;
	int		i;

	offset = proc->pc + 1;
	ocp[0] = ocp_first(bd->ram[MEM_MOD(offset)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(offset)]);
	ocp[2] = ocp_third(bd->ram[MEM_MOD(offset)]);
	offset++;
	ocp[2] = REG_CODE;
	i = 0;
	while (i < 3)
	{
		val[i] = get_value(bd, &offset, ocp[i], 0);
		i++;
	}
	val[0] = proc->r[val[0] - 1];
	proc->r[val[2] - 1] = ((val[0] + val[1])) + proc->pc;
	if (bd->verbose[1])
		verbosity(bd, proc, ocp, val);
	proc->pc = offset;
}

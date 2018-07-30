#include "corewar.h"

static void	verbisity(t_board *bd, t_process *proc, int v1, int v2)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nAdd (r", bd->ram[MEM_MOD(proc->pc - 3)]);
	ft_putstrnbrstr(" + r", bd->ram[MEM_MOD(proc->pc - 2)], ") to r");
	ft_putnbrstrnbr(bd->ram[MEM_MOD(proc->pc - 1)], " -> (", (v1 + v2));
	ft_putnbrstrnbr(v1, " + ",  v2);
	ft_putstrnbrstr(") = ", v1 + v2, ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}

static int	valid_instruction(t_board *bd, t_process *proc)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (bd->ram[MEM_MOD(proc->pc + 2 + i)] < 1
			|| bd->ram[MEM_MOD(proc->pc + 2 + i)] > 16)
			return (0);
		i++;
	}
	return (1);
}

void	add(t_board *bd, t_process *proc)
{
	int				v1;
	int				v2;

	printf("qdd\n");
	if (valid_instruction(bd, proc))
	{
		v1 = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1];
		v2 = proc->r[bd->ram[MEM_MOD(proc->pc + 3)] - 1];
		proc->carry = (!(v2 + v1)) ? 1 : 0;
		if (bd->ram[MEM_MOD(proc->pc + 4)])
			proc->r[bd->ram[MEM_MOD(proc->pc + 4)] - 1] = v1 + v2;
		if (bd->verbose[1])
			verbisity(bd, proc, v1, v2);
	}
	proc->pc += 5;
}
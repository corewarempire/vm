#include "corewar.h"

void	sub(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				v1;
	int				v2;

	pc = proc->pc + 2;
	printf("sub:\n");
	v1 = proc->r[bd->ram[MEM_MOD(pc++)] - 1];
	v2 = proc->r[bd->ram[MEM_MOD(pc++)] - 1];
	proc->carry = (!(v1 + v2)) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(pc++)] - 1] = (v1 - v2);
	proc->pc = pc;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nSub (r", bd->ram[MEM_MOD(proc->pc - 3)]);
	ft_putstrnbrstr(" - r", bd->ram[MEM_MOD(proc->pc - 2)], ") to r");
	ft_putnbrstrnbr(bd->ram[MEM_MOD(proc->pc - 1)], " = ", v1 - v2);
	ft_putstrnbrstr(". Carry : ", proc->carry, "\n\n");
}

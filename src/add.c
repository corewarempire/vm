#include "corewar.h"

static void	verbisity(t_board *bd, t_process *proc, int v1, int v2)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nAdd (r", bd->ram[MEM_MOD(proc->pc - 3)]);
	ft_putstrnbrstr(" + r", bd->ram[MEM_MOD(proc->pc - 2)], ") to r");
	ft_putnbrstrnbr(bd->ram[MEM_MOD(proc->pc - 1)], " = ", (v1 + v2));
	ft_putstrnbrstr(". Carry : ", proc->carry, "\n\n");
}

void	add(t_board *bd, t_process *proc)
{
	unsigned int 	pc;
	int				v1;
	int				v2;

	proc->pc += 2;
	printf("add:\n");
	v1 = proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	v2 = proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	proc->carry = (!v2) ? 1 : 0;
	if (bd->ram[MEM_MOD(proc->pc)])
		proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = v1 + v2;
	proc->pc++;
	if (bd->verbose[1])
		verbisity(bd, proc, v1, v2);
}
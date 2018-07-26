#include "corewar.h"

void	sub(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				res;

	pc = proc->pc + 2;
	res = 0;
	res += proc->r[bd->ram[MEM_MOD(pc++)] - 1];
	res -= proc->r[bd->ram[MEM_MOD(pc++)] - 1];
	proc->carry = (!res) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(pc++)] - 1] = res;
	proc->pc = pc;
}

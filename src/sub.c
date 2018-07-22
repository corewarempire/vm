#include "corewar.h"

void	sub(t_board *bd, t_process *proc)
{
	int				res;

	proc->pc += 2;
	res = 0;
	// printf("sub\n");
	res += proc->r[bd->ram[MEM_MOD(proc->pc++)] - 1];
	res -= proc->r[bd->ram[MEM_MOD(proc->pc++)] - 1];
	proc->carry = (!res) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(proc->pc++)] - 1] = res;
}
#include "corewar.h"

void	add(t_board *bd, t_process *proc)
{
	unsigned int 	pc;
	int				res;

	pc = proc->pc;
	res = 0;
	res += proc->r[bd->ram[MEM_MOD(pc + 2)] - 1];
	res += proc->r[bd->ram[MEM_MOD(pc + 3)] - 1];
	proc->carry = (!res) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(pc + 4)] - 1] = res;
	proc->pc += 5;
}
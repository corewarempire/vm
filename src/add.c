#include "corewar.h"

void	add(t_board *bd, t_process *proc)
{
	unsigned int 	pc;
	int				res;

	proc->pc += 2;
	res = 0;
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	proc->carry = (!res) ? 1 : 0;
	if (bd->ram[MEM_MOD(proc->pc)])
		proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = res;
	proc->pc++;
}
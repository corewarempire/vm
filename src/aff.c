#include "corewar.h"

void	aff(t_board *bd, t_process *proc)
{
	int				r;

	r = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1] % 256;
	// printf("aff:\nRegistry insdex %d => %d\n", bd->ram[MEM_MOD(proc->pc + 2)], r);
	proc->pc += 3;
}
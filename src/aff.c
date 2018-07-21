#include "corewar.h"

void	aff(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				r;

	pc = proc->pc;
	r = proc->r[bd->ram[MEM_MOD(pc + 2)]] % 256;
	proc->pc += 3;
}
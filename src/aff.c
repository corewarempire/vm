#include "corewar.h"

void	aff(t_board *bd, t_process *proc)
{
	int				r;

	printf("aff:\n");
	r = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1] % 256;
	// ft_printf("aff : %c\n", r);
	proc->pc += 3;
}
#include "corewar.h"

void	aff(t_board *bd, t_process *proc)
{
	char	r;

	r = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1] % 256;
	ft_putstr("Aff:");
	write(1, &r, 1);
	write(1, "\n", 1);
	proc->pc += 3;
}
#include "corewar.h"

void	zjmp(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	pc = proc->pc;
	printf("zjump:\n");
	val = get_dir2(bd, pc + 1);
	bd->ram[MEM_MOD(proc->pc + 1)] = 255;
	if (proc->carry)
		proc->pc += (val % IDX_MOD);
	else
		proc->pc += 3;
}

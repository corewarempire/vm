#include "corewar.h"

void	zjmp(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	pc = proc->pc;
	// printf("jump:\n");
	val = get_dir2(bd, pc + 1);
	// printf("VAL %d\n", val);
	if (proc->carry)
		proc->pc += (val & IDX_MOD);
	else
		proc->pc += 3;
}
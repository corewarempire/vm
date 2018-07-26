#include "corewar.h"

void	zjmp(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	pc = proc->pc;
	if (proc->id_player == -1)
		printf("jump:\n");
	val = get_dir2(bd, pc + 1);
	printf("VAL %d\n", val);
	bd->ram[MEM_MOD(proc->pc + 1)] = 255;
	if (proc->carry)
		proc->pc += (val % IDX_MOD);
	else
	{
		printf("FAILED\n");
		printf("OLD VALUE %d\n", bd->ram[MEM_MOD(proc->pc)]);
		proc->pc += 3;
		printf("VALUE %d\n", bd->ram[MEM_MOD(proc->pc)]);
//		printf("proslive:%d\n", bd->);
	}
}
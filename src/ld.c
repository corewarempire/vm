#include "corewar.h"

void	ld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp;
	int				val1;

	ocp = ocp_first(bd->ram[MEM_MOD(proc->pc + 1)]);
	if (proc->id_player == -1)
		printf("ld:");
	if (ocp == DIR_CODE)
	{
		printf("DIR_CODE:\n");
		val1 = get_dir4(vm, proc->pc + 2);
	}
	else
	{
		printf("INDIR_CODE:\n");
		val1 = get_indir(vm, proc->pc + 2);
	}
	proc->carry = (!val1) ? 1 : 0;
	proc->pc = pc;
	proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = val1;
	printf("Store value %d to registry index %d\n", val1, bd->ram[MEM_MOD(proc->pc)] - 1);
	proc->pc++;
}
#include "corewar.h"

void	ld(t_board *bd, t_process *proc)
{
	unsigned char	ocp;
	int				val1;
	int				val2;
	int				reg;

	proc->pc++;
	ocp = ocp_first(bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	printf("ld:\n");
	if (!(val1 = get_params(bd, proc, &proc->pc, (int[2]){ocp, 0})))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = val1;
	printf("Store value %d to registry index %d => res %d\n", val1, bd->ram[MEM_MOD(proc->pc)] - 1, proc->r[bd->ram[MEM_MOD(proc->pc)] - 1]);
	proc->pc++;
}
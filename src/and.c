#include "corewar.h"

void		and(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[2];
	int				val1;
	int				val2;

	proc->pc++;
	// printf("and:\n");
	ocp[0] = ocp_first(bd->ram[MEM_MOD(proc->pc)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 0, 0});
	val2 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 0, 0});
	// printf("VAL1 %d\n", val1);
	// printf("VAL2 %d\n", val2);
	// printf("Store to registry index %d\n", bd->ram[MEM_MOD(proc->pc)] - 1);
	if ((proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = val1 & val2) == 0)
	{
		proc->carry = 1;
		// printf("CARRY 1\n");
	}
	else
	{
		proc->carry = 0;
		// printf("CARRY 0\n");
	}
	proc->pc++;
}

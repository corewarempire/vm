#include "corewar.h"

void	ld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val1;
	int				val2;
	int				reg;
	unsigned char	ocp;

	pc = proc->pc;
	pc++;
	ocp = ocp_first(bd->ram[MEM_MOD(pc)]);
	pc++;
	if (proc->id_player == -1)
		printf("ld:");
	if (!(val1 = get_params(bd, proc, &pc, (int[3]){ocp, 0, 0})))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[bd->ram[MEM_MOD(pc)] - 1] = val1;
	printf("Store value %d to registry index %d => res %d\n", val1, bd->ram[MEM_MOD(pc)] - 1, proc->r[bd->ram[MEM_MOD(pc)] - 1]);
	pc++;
	proc->pc = pc;
}
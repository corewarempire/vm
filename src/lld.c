#include "corewar.h"

void	lld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp;
	int				val1;

	pc = proc->pc;
	pc++;
	ocp = ocp_first(bd->ram[MEM_MOD(pc)]);
	pc++;
	if (proc->id_player == -1)
		printf("lld:%d:", proc->pc);
	if (ocp == IND_CODE)
		printf("ind:");
	else
		printf("dir:");
	proc->carry = (!(val1 = get_params(bd, proc, &pc, (int[3]){ocp, 0, 1}))) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(pc)] - 1] = val1;
	printf("Store value %d to registry index %d\n", val1, bd->ram[MEM_MOD(pc)] - 1);
	pc++;
	proc->pc = pc;
}

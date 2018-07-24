#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val0;

	pc = proc->pc++;
	if (proc->id_player == -1)
		printf("sti\n");
	ocp[0] = ocp_first(bd->ram[MEM_MOD(proc->pc)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(proc->pc)]);
	ocp[2] = ocp_third(bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	val0 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 0, 0});
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 0})
			+ get_params(bd, proc, &proc->pc, (int[3]){ocp[2], 1, 0});
	proc->carry = (!val1) ? 1 : 0;
	printf("DIFF %d\n", proc->pc - pc);
	printf("STOP ON VALUE %u\n", bd->ram[proc->pc]);
	set_ramvalue(bd, (pc + val1) % IDX_MOD, val0);
}
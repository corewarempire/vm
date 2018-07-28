#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val0;

	pc = proc->pc + 1;
	// printf("sti\n");
	ocp[0] = REG_CODE;
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(pc)]);
	ocp[2] = ocp_third(bd->ram[MEM_MOD(pc)]);
	pc++;
	val0 = get_params(bd, proc, &pc, (int[3]){ocp[0], 0, 0});
	val1 = get_params(bd, proc, &pc, (int[3]){ocp[1], 1, 0})
			+ get_params(bd, proc, &pc, (int[3]){ocp[2], 1, 0});
	proc->carry = (!val1) ? 1 : 0;
	set_ramvalue(bd, (proc->pc + val1) % IDX_MOD, val0);
	proc->pc = pc;
}

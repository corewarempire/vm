#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val0;

	proc->pc++;
	// printf("sti\n");
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	ocp[2] = ocp_third(bd->ram[proc->pc]);
	proc->pc++;
	val0 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 0, 0});
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 0})
			+ get_params(bd, proc, &proc->pc, (int[3]){ocp[2], 1, 0});
	proc->carry = (!val1) ? 1 : 0;
	set_ramvalue(bd, proc->pc + val1, val0);
}
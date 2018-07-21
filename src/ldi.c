#include "corewar.h"

void	ldi(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[2];
	int				val1;
	int				val2;

	proc->pc++;
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	val1 = get_params(bd, proc, &pc, (int[2]){ocp[0], 1});
	val2 = get_params(bd, proc, &pc, (int[2]){ocp[1], 1});
	if (!(proc->r[bd->ram[pc]] = val1 + val2))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc + 1;
}
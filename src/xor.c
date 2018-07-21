#include "corewar.h"

void	xor(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[2];
	int				val1;
	int				val2;

	pc = proc->pc + 1;
	ocp[0] = ocp_first(bd->ram[MEM_MOD(pc)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(pc)]);
	pc++;
	val1 = get_params(bd, proc, &pc, (int[2]){ocp[0], 0});
	val2 = get_params(bd, proc, &pc, (int[2]){ocp[1], 0});
	if (!(proc->r[bd->ram[MEM_MOD(pc)]] = val1 ^ val2))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc + 1;
}
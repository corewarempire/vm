#include "corewar.h"

void	ldi(t_board *bd, t_process *proc)
{
	unsigned char	ocp[2];
	unsigned int	pc;
	int				val1;
	int				val2;

	pc = proc->pc + 1;
	printf("ldi\n");
	ocp[0] = ocp_first(bd->ram[MEM_MOD(proc->pc)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 1, 0});
	val2 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 0});
	if (!(proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = pc + ((val1 + val2) % IDX_MOD)))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc++;
	if (!bd->verbose[1])
		return ;
}

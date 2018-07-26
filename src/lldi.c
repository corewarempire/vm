#include "corewar.h"

void	lldi(t_board *bd, t_process *proc)
{
	unsigned char	ocp[2];
	unsigned int	pc;
	int				val1;
	int				val2;

	pc = proc->pc;
	proc->pc++;
	printf("lldi ");
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	if (ocp[0] == DIR_CODE)
		printf("DIR ");
	else if (ocp[0] == IND_CODE)
		printf("INDDIR ");
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	if (ocp[1] == DIR_CODE)
		printf("DIR ");
	else if (ocp[1] == IND_CODE)
		printf("INDDIR ");
	proc->pc++;
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 1, 1});
	val2 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 1});
	if (!(proc->r[bd->ram[proc->pc]] = pc + ((val1 + val2) % IDX_MOD)))
		proc->carry = 1;
	else
		proc->carry = 0;
	printf("%d %d r%d\n", val1, val2, bd->ram[proc->pc]);
	printf("=>%d\n", proc->r[bd->ram[proc->pc]]);
	proc->pc++;
}
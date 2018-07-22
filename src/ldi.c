#include "corewar.h"

void	ldi(t_board *bd, t_process *proc)
{
	unsigned char	ocp[2];
	int				val1;
	int				val2;

	proc->pc++;
	// printf("ldi\n");
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	proc->pc++;
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 1, 0});
	// printf("VALUE PC %d\n", bd->ram[MEM_MOD(proc->pc)]);
	val2 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 0});
	// printf("VAL1 %d\n", val1);
	// printf("VAL2 %d\n", val2);
	// printf("Store to registry index %d\n", bd->ram[MEM_MOD(proc->pc)] - 1);
	if (!(proc->r[bd->ram[proc->pc]] = val1 + val2))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc++;
	// printf("VALUE CASE %c\n", bd->ram[MEM_MOD(proc->pc)]);
}
#include "corewar.h"

void	add(t_board *bd, t_process *proc)
{
	unsigned int 	pc;
	int				res;

	proc->pc += 2;
	res = 0;
	if (proc->id_player == -1)
		printf("add:");
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	printf("r%d ", bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	printf("r%d ", bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
	// printf("get registry index {%d} res %d\n", bd->ram[MEM_MOD(proc->pc)] - 1, res);
	proc->carry = (!res) ? 1 : 0;
	if (bd->ram[MEM_MOD(proc->pc)])
		proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = res;
	printf("r%d \n", bd->ram[MEM_MOD(proc->pc)]);
	proc->pc++;
}
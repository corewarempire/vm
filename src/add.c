#include "corewar.h"

void	add(t_board *bd, t_process *proc)
{
	unsigned int 	pc;
	int				res;

	proc->pc += 2;
	res = 0;
	// printf("add:\n");
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	// printf("get registry index {%d} res %d\n", bd->ram[MEM_MOD(proc->pc)] - 1, res);
	res += proc->r[bd->ram[MEM_MOD(proc->pc)] - 1];
	proc->pc++;
	// printf("get registry index {%d} res %d\n", bd->ram[MEM_MOD(proc->pc)] - 1, res);
	proc->carry = (!res) ? 1 : 0;
	proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = res;
	// printf("Set to registre %d value %d\n", bd->ram[MEM_MOD(proc->pc)] - 1, res);
	proc->pc++;
	// printf("%d\n", bd->ram[MEM_MOD(proc->pc)]);
}
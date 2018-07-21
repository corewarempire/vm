#include "corewar.h"

int			get_params(t_board *bd, t_process *proc, int *pc, int data[2])
{
	int res;

	res = 0;
	if (data[0] == T_IND)
	{
		res = proc->r[bd->ram[*pc] - 1];
		(*pc)++;
	}
	else if (data[0] == T_IND)
	{
		res = get_indir(bd, pc);
		(*pc) += 2;
	}
	else
	{
		res = (!data[2]) ? get_dir4(bd, pc) : get_dir2(bd, pc);
		(*pc) += (!data[2]) ? 4 : 2;
	}
	return (res);
}
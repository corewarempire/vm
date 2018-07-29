#include "corewar.h"

int			get_params(t_board *bd, t_process *proc, unsigned int *pc, int data[3])
{
	int res;

	res = 0;
	if (data[0] == REG_CODE)
	{
		res = proc->r[bd->ram[MEM_MOD(*pc)] - 1];
		(*pc)++;
	}
	else if (data[0] == DIR_CODE)
	{
		res = (!data[1]) ? get_dir4(bd, *pc) : get_dir2(bd, *pc);
		(*pc) += (!data[1]) ? 4 : 2;
	}
	else
	{
		res = (!data[2]) ? get_indir(bd, *pc) : get_long_indir(bd, *pc);
		(*pc) += 2;
	}
	return (res);
}
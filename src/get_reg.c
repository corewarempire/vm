#include "corewar.h"

int		get_reg(t_process *proc, unsigned int index)
{
	int ret;

	ret = proc->r[index - 1];
	return (ret);
}
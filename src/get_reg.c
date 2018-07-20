#include "corewar.h"

unsigned char	get_reg(t_process *proc, unsigned int index)
{
	unsigned char ret;

	ret = proc->r[index - 1];
	return (ret);
}
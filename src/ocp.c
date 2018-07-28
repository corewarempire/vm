#include "corewar.h"

// 11223300
// 3 en binaire <=> 11
// Donc decaler puis AND sur bit

void		get_ocp(t_board *bd, unsigned int pos, int *ocp)
{
	ocp[0] = ocp_first(bd->ram[MEM_MOD(proc->pc + 1)]);
	ocp[1] = ocp_first(bd->ram[MEM_MOD(proc->pc + 1)]);
	ocp[2] = ocp_scd(bd->ram[MEM_MOD(proc->pc + 1)]);
}

int			calc_offset(int ocp[3], int flag)
{
	int i;
	int offset;

	i = 0;
	offset = 0;
	while (i < 3)
	{
		if (ocp[i] == REG_CODE)
			offset += 1;
		else if (ocp[i] == IND_COD)
			offset += 2;
		else if (ocp[i] == DIR_CODE)
			offset += (flag) ? 4 : 2;
		i++;
	}
	return (offset);
}

unsigned int	ocp_first(unsigned char c)
{
	return (c >> 6);
}

unsigned int	ocp_scd(unsigned char c)
{
	return ((c >> 4) & 3);
}

unsigned int	ocp_third(unsigned char c)
{
	return ((c >> 2) & 3);
}

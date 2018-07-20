#include "corewar.h"

void	set_ramvalue(t_board *bd, unsigned int pc, unsigned int value)
{
	bd->ram[MEM_MOD(pos)] = val >> 24;
	bd->ram[MEM_MOD(pos + 1)] = val >> 16;
	bd->ram[MEM_MOD(pos + 2)] = val >> 8;
	bd->ram[MEM_MOD(pos + 3)] = val;
}
#include "corewar.h"

void	set_ramvalue(t_board *bd, unsigned int pc, unsigned int value)
{
	bd->ram[MEM_MOD(pc)] = value >> 24;
	bd->ram[MEM_MOD(pc + 1)] = value >> 16;
	bd->ram[MEM_MOD(pc + 2)] = value >> 8;
	bd->ram[MEM_MOD(pc + 3)] = value;
}
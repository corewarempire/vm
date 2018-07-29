#include "corewar.h"

// Modulo a rajouter de memsize? IDK

int		get_indir(t_board *bd, unsigned int pos)
{
	int		ret;
	short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	addr %= IDX_MOD;
	return (addr);
}

int		get_long_indir(t_board *bd, unsigned int pos)
{
	int		ret;
	short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	return (addr);
}

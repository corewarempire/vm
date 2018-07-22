#include "corewar.h"

// Modulo a rajouter de memsize? IDK

int		get_indir(t_board *bd, unsigned int pos)
{
	int				ret;
	unsigned short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	addr = addr % IDX_MOD;
	ret = (bd->ram[MEM_MOD(addr)] << 24)
			| (bd->ram[MEM_MOD(pos + 1 + addr)] << 16)
			| (bd->ram[MEM_MOD(pos + 2 + addr)] << 8)
			| bd->ram[MEM_MOD(pos + 3 + addr)];
	return (ret);
}

int		get_long_indir(t_board *bd, unsigned int pos)
{
	int				ret;
	unsigned short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	ret = (bd->ram[MEM_MOD(addr)] << 24)
			| (bd->ram[MEM_MOD(pos + addr + 1)] << 16)
			| (bd->ram[MEM_MOD(pos + addr + 2)] << 8)
			| bd->ram[MEM_MOD(pos + addr + 3)];
	return (ret);
}

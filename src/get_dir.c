#include "corewar.h"

// cf => https://fr.wikipedia.org/wiki/Endianness#Big_endian

int		get_dir4(t_board *bd, unsigned int pos)
{
	int ret;

	ret = 0;
	ret = (bd->ram[MEM_MOD(pos)] << 24)
		| (bd->ram[MEM_MOD(pos + 1)] << 16)
		| (bd->ram[MEM_MOD(pos + 2)] << 8)
		| bd->ram[MEM_MOD(pos + 3)];
	return (ret);
}

short	get_dir2(t_board *bd, unsigned int pos)
{
	short ret;

	ret = 0;
	ret = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	return (ret);
}

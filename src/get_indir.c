#include "corewar.h"

// Modulo a rajouter de memsize? IDK

int		get_indir(t_board *bd, t_process *proc, unsigned int pos)
{
	int		ret;
	short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	addr %= IDX_MOD;
	ret = (bd->ram[MEM_MOD(proc->pc + addr)] << 24)
			| (bd->ram[MEM_MOD(proc->pc + 1 + addr)] << 16)
			| (bd->ram[MEM_MOD(proc->pc + 2 + addr)] << 8)
			| bd->ram[MEM_MOD(proc->pc + 3 + addr)];
	return (ret);
}

int		get_long_indir(t_board *bd, t_process *proc, unsigned int pos)
{
	int		ret;
	short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	ret = (bd->ram[MEM_MOD(proc->pc + addr)] << 24)
			| (bd->ram[MEM_MOD(proc->pc + 1 + addr)] << 16)
			| (bd->ram[MEM_MOD(proc->pc + 2 + addr)] << 8)
			| (bd->ram[MEM_MOD(proc->pc + 3 + addr)]);
	return (ret);
}

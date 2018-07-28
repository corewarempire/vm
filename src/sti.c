#include "corewar.h"

void	sti(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val[3];
	int				offset;

	pc = proc->pc;
	ocp[0] = ocp_scd(bd->ram[MEM_MOD(pc + 1)]);
	ocp[1] = ocp_third(bd->ram[MEM_MOD(pc + 1)]);
	val[0] = proc->r[bd->ram[pc + 2] - 1];
	if (ocp[0] == REG_CODE)
	{
		val[1] = proc->r[bd->ram[pc + 3] - 1];
		val[2] = (ocp[2] == IND_CODE) ? get_indir(bd, proc, pc + 4) : get_dir2(bd, pc + 4);
		offset = 5;
	}
	else
	{
		val[1] = (ocp[0] == IND_CODE) get_indir(bd, proc, pc + 4) : get_dir2(bd, pc + 4);
		val[2] = (ocp[1] == IND_CODE) get_indir(bd, proc, pc + 6) : get_dir2(bd, pc + 6);
		offset = 7;
	}
	set_ramvalue(bd, (proc->pc + val[1] + val[2]) % IDX_MOD, val[0]);
	proc->pc += offset;
}

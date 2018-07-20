#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	int	octal;
	int first_reg;
	int value;

	octal = ocp_scd(bd->ram[proc->pc + 1]);
	first_reg = get_reg(proc, bd->ram[proc->pc + 2]);
	value = (octal & 3) ? get_indir(bd, proc->pc + 3) : get_reg(proc, proc->pc + 3);
	proc->carry = (!first_reg) ? 1 : 0;
	printf("Here : %d\n", first_reg);
	printf("%d \n", get_indir(bd, proc->pc + 3));
	printf("%u \n", proc->pc);
	
	if (octal & 3)
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), first_reg);
	else if (octal & T_REG)
		proc->r[value - 1] = first_reg;
	// avancer de une case pc ou de la totalite de l'info?
}
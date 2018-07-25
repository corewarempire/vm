#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	// int	octal;
	// int first_reg;
	// int value;

	// proc->pc++;
	// octal = ocp_scd(bd->ram[MEM_MOD(proc->pc)]);
	// // printf("Octal %d\n", octal);
	// proc->pc++;
	// first_reg = get_params(bd, proc, &proc->pc, (int[3]){T_REG, 0, 0});
	// // printf("Registre contain %d\n", first_reg);
	// value = (octal == IND_CODE) ? get_indir(bd, proc->pc + 3) : get_reg(proc, proc->pc + 3);
	// // printf("Value %d\n", value);
	// proc->carry = (!first_reg) ? 1 : 0;
	// // printf("exec st:\n");
	// if (octal == IND_CODE)
	// 	set_ramvalue(bd, proc->pc + (value % IDX_MOD), first_reg);
	// else if (octal & T_REG)
	// {
	// 	proc->r[value - 1] = first_reg;
	// 	// printf("Set from registre %d to %d\n", first_reg, value);
	// }
	// proc->pc = (octal == IND_CODE) ? 5 : 4;
}
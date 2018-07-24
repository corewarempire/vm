#include "corewar.h"

void	get_instruction(t_board *bd, t_process *proc)
{
	unsigned char	c;

	if (proc->op_code)
		return ;
	c = bd->ram[MEM_MOD(proc->pc)];
	if (c > 0 && c < 17)
	{
		proc->exec_cycle = op_tab[c].cycles;
		proc->op_code = op_tab[c].op_code;
		// if (proc->id_player == -1)
			// printf("Set new instruction %d at cycle %d, exec at %d\n", proc->op_code, bd->cycle, bd->cycle + op_tab[c].cycles);
	}
}

int		exec_instruction(t_board *bd, t_process *proc)
{
	static void	(*f[])() = {NULL, live, ld, st, add, sub, and,
							or, xor, zjmp, ldi, sti, frk, lld,
							lldi, lfork, aff};
	if (proc->exec_cycle == 1)
	{
		if (proc->id_player == -1)
			// printf("FUNCTION %s\n", op_tab[proc->op_code].name);
		f[proc->op_code](bd, proc);
		proc->op_code = 0;
		proc->exec_cycle = 0;
		get_instruction(bd, proc);
		// if (proc->id_player == -1 && proc->op_code)
			// printf("NEW instruction directly load code %d\n", proc->op_code);
	}
	else
		(proc->exec_cycle)--;
	return (1);
}

int		check_instruction(t_board *bd, t_process *proc)
{
	get_instruction(bd, proc);
	if (proc->op_code)
		exec_instruction(bd, proc);
	else
		proc->pc = MEM_MOD(proc->pc + 1);
	return (1);
}
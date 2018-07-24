#include "corewar.h"

t_op	op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
};

int		exec_instruction(t_board *bd, t_process *proc)
{
	static void	(*f[])() = {NULL, live, ld, st, add, sub, and,
							or, xor, zjmp, ldi, sti, frk, lld,
							lldi, lfork, aff};
	if (proc->op_code && !proc->exec_cycle)
	{
		printf("FUNCTION %s\n", op_tab[proc->op_code].name);
		f[proc->op_code](bd, proc);
		proc->op_code = 0;
		proc->exec_cycle = 0;
	}
	else if (proc->op_code)
		(proc->exec_cycle)--;
	return (1);
}

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
		printf("Set new instruction %d at cycle %d, exec at %d\n", proc->op_code, bd->cycle, bd->cycle + op_tab[c].cycles);
	}
}

int		check_instruction(t_board *bd, t_process *proc)
{
	get_instruction(bd, proc);
	if (proc->op_code)
		exec_instruction(bd, proc);
	else
	{
		proc->pc = MEM_MOD(proc->pc + 1);
	}
	return (1);
}
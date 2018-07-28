#include "corewar.h"

void		and(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned char	ocp[3];
	int				val1;
	int				val2;

	pc = proc->pc + 1;
	printf("and:\n");
	ocp[0] = ocp_first(bd->ram[MEM_MOD(pc)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(pc)]);
	pc++;
	val1 = get_params(bd, proc, &pc, (int[3]){ocp[0], 0, 0});
	val2 = get_params(bd, proc, &pc, (int[3]){ocp[1], 0, 0});
	ocp[2] = bd->ram[MEM_MOD(pc)];
	if ((proc->r[bd->ram[MEM_MOD(pc)] - 1] = val1 & val2) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc = pc + 1;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nAND (", val1);
	ft_putstrnbrstr(" & ", val2, ") to r");
	ft_putnbrstrnbr((int)ocp[2], " = ", (val1 & val2));
	ft_putstrnbrstr(". Carry : ", proc->carry, "\n\n");
}

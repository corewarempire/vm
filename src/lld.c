#include "corewar.h"

void	lld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val1;
	unsigned char	ocp;

	pc = proc->pc;
	pc++;
	ocp = ocp_first(bd->ram[MEM_MOD(pc)]);
	pc++;
	if (!(val1 = get_params(bd, proc, &pc, (int[3]){ocp, 0, 1})))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[bd->ram[MEM_MOD(pc)] - 1] = val1;
	proc->pc = pc + 1;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLld ", val1);
	ft_putstrnbrstr(" in r", bd->ram[MEM_MOD(proc->pc) - 1], ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}

#include "corewar.h"

void	lldi(t_board *bd, t_process *proc)
{
	unsigned char	ocp[2];
	unsigned int	pc;
	int				val1;
	int				val2;

	pc = proc->pc;
	proc->pc++;
	printf("lldi\n");
	ocp[0] = ocp_first(bd->ram[proc->pc]);
	ocp[1] = ocp_scd(bd->ram[proc->pc]);
	proc->pc++;
	val1 = get_params(bd, proc, &proc->pc, (int[3]){ocp[0], 1, 1});
	val2 = get_params(bd, proc, &proc->pc, (int[3]){ocp[1], 1, 1});
	if (!(proc->r[bd->ram[MEM_MOD(proc->pc)] - 1] = pc + ((val1 + val2))))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc++;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLld ", val1);
	ft_putstrnbrstr(" in r", bd->ram[MEM_MOD(proc->pc) - 1], ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");

	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLdi ", (pc + ((val1 + val2))));
	ft_putstrnbrstr(" in r", bd->ram[proc->pc - 1], ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}

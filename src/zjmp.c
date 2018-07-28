#include "corewar.h"

void	zjmp(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	int				val;

	pc = proc->pc;
	// printf("zjump:\n");
	val = get_dir2(bd, pc + 1);
	if (proc->carry)
		proc->pc += (val % IDX_MOD);
	else
		proc->pc += 3;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nZjmp to ", (val % IDX_MOD));
	proc->carry ? ft_putstr(" Success\n\n") : ft_putstr("Failed\n\n");
}

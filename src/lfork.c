#include "corewar.h"

static void	verbosity(t_process *proc, t_process *new)
{
	ft_putstrnbrstr("Player ", new->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLong Fork, new PC on ", new->pc);
	ft_putstrnbrstr(". Carry : ", new->carry, "\n\n");
}

void	lfork(t_board *bd, t_process *proc)
{
	t_process		*new;
	unsigned int	pc;
	int				newpc;

	newpc = get_dir2(bd, proc->pc + 1);
	if (!(new = add_process(bd->lst_process, bd->id_process++, proc->id_player, proc->pc)))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
	new->pc = proc->pc + newpc;
	proc->pc += 3;
	update_process_count(bd, proc->id_player, 1);
	if (bd->verbose[1])
		verbosity(proc, new);
}

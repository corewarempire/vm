#include "corewar.h"

	// {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},


static void	verbosity(t_process *proc, t_process *new)
{
	ft_putstrnbrstr("Player ", new->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nFork, new PC on ", MEM_MOD(new->pc));
	ft_putstrnbrstr(". Carry : ", new->carry, "\n\n");
}

void	frk(t_board *bd, t_process *proc)
{
	t_process		*new;
	unsigned int	pc;
	int				newpc;

	newpc = get_dir2(bd, proc->pc + 1);
	if (!(new = add_process(bd->lst_process, bd->id_process++, proc->id_player, proc->pc)))
	{
		proc->pc += 3;
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
		return ;
	}
	new->pc = proc->pc + (newpc % IDX_MOD);
	proc->pc += 3;
	update_process_count(bd, proc->id_player, 1);
	if (bd->verbose[1])
		verbosity(proc, new);
}

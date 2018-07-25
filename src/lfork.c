#include "corewar.h"

void	lfork(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	t_process		*new;
	int				newpc;
	char			b;
	unsigned char	byte_code;

	pc = proc->pc;
	printf("lfork\n");
	newpc = proc->pc + get_params(bd, proc, &pc, (int[3]){DIR_CODE, 1, 1});
	byte_code = bd->ram[MEM_MOD(newpc)];
	if (!(new = add_process(bd->lst_process, bd->id_process++, proc->id_player, newpc)))
		printf("FAILED TO CREATE FORK NEED TO EXIT\n");
	b = (byte_code > 0 && byte_code <= 16);
	new->op_code = (b) ? byte_code : 0;
	new->exec_cycle = (b) ? op_tab[byte_code].cycles : 0;
	proc->pc += 3;
	// *new = *proc;
}
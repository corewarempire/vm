#include "corewar.h"

// void	lfork(t_vm *vm, t_process *process)
// {
// 	t_process		*new_p;
// 	unsigned int	pc;
// 	int				bool_;
// 	short			target;
// 	unsigned char	byte_code;

// 	if (!(new_p = malloc(sizeof(t_process))))
// 		p_error();
// 	pc = process->pc;
// 	target = (short)get_dir(vm, pc + 1, 1);
// 	ft_memcpy(new_p, process, sizeof(t_process));
// 	new_p->pc += (target);
// 	byte_code = vm->map[PTR(new_p->pc)];
// 	vm->nb_process += 1;
// 	if (vm->flag & verbose)
// 		ft_printf("P %4d | lfork %hd (%d)\n", process->id, target, target);
// 	bool_ = (byte_code > 0 && byte_code <= 16);
// 	new_p->op_code = bool_ ? byte_code : 0;
// 	new_p->exec_cycle = bool_ ? g_op_tab[byte_code].cycles + vm->cycle : 0;
// 	new_p->id = vm->id_track++;
// 	push_lst__(&vm->process, new_p);
// 	process->pc += 3;
// }

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
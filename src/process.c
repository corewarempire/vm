#include "corewar.h"

t_lst_process	*init_list_process(void)
{
	t_lst_process *lst;

	if (!(lst = (t_lst_process*)malloc(sizeof(t_lst_process))))
		return (0);
	lst->process = 0;
	lst->len = 0;
	return (lst);
}

t_process		*new_process(unsigned int r1, unsigned int pc)
{
	t_process *new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (0);
	new->pc = pc;
	new->r[0] = r1;
	new->id_player = r1;
	new->next = 0;
	return (new);
}

t_process		*add_process(t_lst_process *lst, unsigned int r1, unsigned int pc)
{
	t_process	*process;

	process = lst->process;
	if (process)
	{
		while (process->next)
			process = process->next;
		if (!(process->next = new_process(r1, pc)))
			return (0);
		lst->len++;
		return (process->next);
	}
	else
	{
		lst->process = new_process(r1, pc);
		lst->len++;
		return (lst->process);
	}
}

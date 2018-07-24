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

t_process		*new_process(unsigned int id_process, unsigned int r1, unsigned int pc)
{
	int i;
	t_process *new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (0);
	i = 0;
	while (i < REG_NUMBER)
		new->r[i++] = 0;
	new->pc = pc;
	new->r[0] = r1;
	new->id_player = r1;
	new->op_code = 0;
	new->last_live = 0;
	new->id_process = id_process;
	new->carry = 0;
	new->next = 0;
	return (new);
}

t_process		*add_process(t_lst_process *lst, unsigned int id_process, int r1, unsigned int pc)
{
	t_process	*process;
	t_process	*new;

	process = lst->process;
	if (!(new = new_process(id_process, r1, MEM_MOD(pc))))
		return (0);
	if (process)
	{
		new->next = process;
		lst->process = new;
		lst->len++;
		return (new);
	}
	else
	{
		lst->process = new;
		lst->len++;
		return (new);
	}
}

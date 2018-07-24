/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/24 16:18:31 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process(t_process *proc)
{
	free(proc);
}

void	pkill(t_board *bd, t_process **last, t_process **curr)
{
	t_process *tmp;

	tmp = (*curr)->next;
	if (!(*last))
	{
		free_process(*curr);
		bd->lst_process->process = tmp;
		*curr = tmp;
	}
	else
	{
		printf("1\n");
		(*last)->next = tmp;
		free_process(*curr);
		*curr = tmp;
		printf("2\n");
	}
}

void	purge_process(t_board *bd)
{
	t_process *proc;
	t_process *last;

	proc = bd->lst_process->process;
	last = 0;
	while (proc)
	{
		if (proc->last_live <= bd->last_check_purge)
		{
			printf("pkill Cycle:%d Position:%d\n", bd->cycle, proc->pc);
			pkill(bd, &last, &proc);
		}
		else
		{
			last = proc;
			proc = proc->next;
		}
	}
}

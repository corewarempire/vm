/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/28 15:37:58 by akarasso         ###   ########.fr       */
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
		(*last)->next = tmp;
		free_process(*curr);
		*curr = tmp;
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
			update_process_count(bd, proc->id_player, -1);
			pkill(bd, &last, &proc);
		}
		else
		{
			last = proc;
			proc = proc->next;
		}
	}
}

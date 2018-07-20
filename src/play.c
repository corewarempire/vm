/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:24:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/20 10:25:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	run(t_board *board)
{
	t_process *proc;

	write(1, "START\n", 6);
	proc = board->lst_process->process;
	// while (board->lst_process->len)
	// {
		if (check_instruction(board, proc))
		{
			printf("CHECK PROCESS AT %u\n", proc->pc);
		}
		proc = (proc->next) ? proc->next : board->lst_process->process;
	// }
	write(1, "END\n", 4);
}

void	play(t_board *board)
{
	printf("%d\n", board->champions_count);
	if (board->champions_count < 1)
		return ;
	if (!init_process(board))
		return ;
	board->cycle_to_die = CYCLE_TO_DIE;
	run(board);
}
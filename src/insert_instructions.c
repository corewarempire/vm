/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:15:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/30 23:48:29 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		insert_code(t_board *bd, int pos)
{
	t_champ			*tmp;
	unsigned char	str;

	tmp = bd->first_champ;
	while (tmp->next && tmp->next->fd != 0)
		tmp = tmp->next;
	lseek(tmp->fd, 2192, SEEK_SET);
	while ((read(tmp->fd, &str, 1) > 0))
	{
		bd->ram[pos] = (unsigned char)str;
		pos++;
	}
	close(tmp->fd);
	tmp->fd = 0;
	return (1);
}

int		insert_instructions(t_board *bd)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i < bd->champions_count)
	{
		if (!insert_code(bd, (j * i++)))
			return (ft_error(3, 1));
		j = MEM_SIZE / bd->champions_count;
	}
	return (1);
}

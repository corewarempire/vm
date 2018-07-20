/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:09:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/20 10:20:39 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// Modulo a rajouter de memsize? IDK

int		get_indir(t_board *bd, unsigned int pos)
{
	int				ret;
	unsigned short	addr;

	addr = 0;
	ret = 0;
	addr = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	ret = (bd->ram[MEM_MOD(addr)] << 24)
			| (bd->ram[MEM_MOD(pos + addr + 1)] << 16)
			| (bd->ram[MEM_MOD(pos + addr + 2)] << 8)
			| bd->ram[MEM_MOD(pos + addr + 3)];
	return (ret);
}
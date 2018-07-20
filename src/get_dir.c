/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:54:57 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/20 10:18:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// cf => https://fr.wikipedia.org/wiki/Endianness#Big_endian

int		get_dir4(t_board *bd, unsigned int pos)
{
	int ret;

	ret = 0;
	ret = (bd->ram[MEM_MOD(pos)] << 24)
		| (bd->ram[MEM_MOD(pos + 1)] << 16)
		| (bd->ram[MEM_MOD(pos + 2)] << 8)
		| bd->ram[MEM_MOD(pos + 3)];
	return (ret);
}

short	get_dir2(t_board *bd, unsigned int pos)
{
	short ret;

	ret = 0;
	ret = (bd->ram[MEM_MOD(pos)] << 8) | bd->ram[MEM_MOD(pos + 1)];
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:20:52 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/20 10:23:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	get_reg(t_process *proc, unsigned int index)
{
	unsigned char ret;

	ret = proc->r[index - 1];
	return (ret);
}
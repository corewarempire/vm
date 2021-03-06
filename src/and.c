/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:15:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/31 00:14:32 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		verbosity(t_process *proc, int val[3])
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nAND (", val[0]);
	ft_putstrnbrstr(" & ", val[1], ") to r");
	ft_putnbrstrnbr(val[2], " = ", (val[0] & val[1]));
	ft_putstrnbrstr(". Carry : ", proc->carry, "\n");
}

static	int		get_value(t_board *bd, int *pc, int ocp, int flag)
{
	int res;

	res = 0;
	if (ocp == REG_CODE)
	{
		res = bd->ram[MEM_MOD(*pc)];
		(*pc) += 1;
	}
	else if (ocp == DIR_CODE)
	{
		res = (flag) ? get_dir4(bd, *pc) : get_dir2(bd, *pc);
		(*pc) += (flag) ? 4 : 2;
	}
	else if (ocp == IND_CODE)
	{
		res = (flag) ? get_indir(bd, *pc) : get_indir(bd, *pc);
		(*pc) += 2;
	}
	return (res);
}

static int		valid_args(t_board *bd, t_process *proc, int *ocp, int *val)
{
	if (ocp[0] == REG_CODE && (val[0] < 1 || val[0] > 16))
		return (0);
	if (ocp[1] == REG_CODE && (val[1] < 1 || val[1] > 16))
		return (0);
	if (val[2] < 1 || val[2] > 16)
		return (0);
	if (ocp[0] == REG_CODE)
		val[0] = proc->r[val[0] - 1];
	if (ocp[1] == REG_CODE)
		val[1] = proc->r[val[1] - 1];
	if (ocp[0] == IND_CODE)
		val[0] = get_dir4(bd, proc->pc + (val[0] % IDX_MOD));
	if (ocp[1] == IND_CODE)
		val[1] = get_dir4(bd, proc->pc + (val[1] % IDX_MOD));
	return (1);
}

void			and(t_board *bd, t_process *proc)
{
	int		ocp[3];
	int		val[3];
	int		offset;
	int		i;

	offset = proc->pc + 1;
	ocp[0] = ocp_first(bd->ram[MEM_MOD(offset)]);
	ocp[1] = ocp_scd(bd->ram[MEM_MOD(offset)]);
	ocp[2] = REG_CODE;
	offset++;
	i = 0;
	while (i < 3)
	{
		val[i] = get_value(bd, &offset, ocp[i], 1);
		i++;
	}
	if (valid_args(bd, proc, ocp, val))
	{
		proc->r[val[2] - 1] = val[0] & val[1];
		proc->carry = (!proc->r[val[2] - 1]) ? 1 : 0;
		if (bd->verbose[1])
			verbosity(proc, val);
	}
	proc->pc = offset;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:18:56 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/29 03:09:11 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbosity(t_board *bd, t_process *proc, int *ocp, int *val)
{
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLdi (", val[0]);
	ft_putstrnbrstr(" + ", val[1], ") -> r");
	ft_putnbr(val[2]);
	ft_putstr(".\n\n");
}

static void		ldi_reg_case(t_board *bd, t_process *proc, int *val, int *ocp)
{
	val[0] = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1];
	val[1] = (ocp[1] == DIR_CODE) ? get_dir2(bd, proc->pc + 3)
		: proc->r[bd->ram[MEM_MOD(proc->pc + 3)] - 1];
	val[2] = (ocp[1] == DIR_CODE) ? bd->ram[MEM_MOD(proc->pc + 5)]
		: bd->ram[MEM_MOD(proc->pc + 4)];
}

static void		ldi_other_case(t_board *bd, t_process *proc, int *val, int *ocp)
{
	val[0] = (ocp[0] == DIR_CODE) ? get_dir2(bd, proc->pc + 2)
		: get_indir(bd, proc, proc->pc + 2);
	val[1] = (ocp[1] == DIR_CODE) ? get_dir2(bd, proc->pc + 4)
		: proc->r[bd->ram[MEM_MOD(proc->pc + 4)] - 1];
	val[2] = (ocp[1] == DIR_CODE) ? bd->ram[MEM_MOD(proc->pc + 6)]
		: bd->ram[MEM_MOD(proc->pc + 5)];
}

void			ldi(t_board *bd, t_process *proc)
{
	int				ocp[3];
	int				val[3];
	int				offset;

	get_ocp(bd, proc->pc + 1, ocp);
	(ocp[0] == REG_CODE) ? ldi_reg_case(bd, proc, val, ocp)
		: ldi_other_case(bd, proc, val, ocp);
	offset = calc_offset(ocp, 1);
	printf("Offset return %d\n", offset);
	if (bd->ram[MEM_MOD(val[2])] < 1 || bd->ram[MEM_MOD(val[2])] > 15)
	{
	if (!(proc->r[bd->ram[MEM_MOD(val[2])] - 1]
			= ((proc->pc + ((val[0] + val[1]) % IDX_MOD)))))
		proc->carry = 1;
	else
		proc->carry = 0;
	if (bd->verbose[1])
		verbosity(bd, proc, ocp, val);
	}
	proc->pc += offset;
}

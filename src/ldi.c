/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:18:56 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/29 00:31:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// {"ldi", 3, {	
// 		T_REG | T_DIR | T_IND, 
// 		T_DIR | T_REG, 
// 		T_REG
// 	}, 10, 25,
// 		"load index", 1, 1},

static void		ldi_reg_case(t_board *bd, t_process *proc, int *val)
{
	val[0] = proc->r[bd->ram[MEM_MOD(proc->pc + 2)] - 1];
	val[1] = (ocp[1] == DIR_CODE) ? get_dir2(bd, pc + 3)
		: proc->r[bd->ram[MEM_MOD(proc->pc + 3)] - 1];
	val[2] = (ocp[1] == DIR_CODE) ? bd->ram[MEM_MOD(proc->pc + 5)]
		: bd->ram[MEM_MOD(proc->pc + 4)];
}

static void		ldi_other_case(t_board *bd, t_process *proc, int *val)
{
	val[0] = (ocp[0] == DIR_CODE) ? get_dir2(bd, proc->pc + 2)
		: get_ind(bd, proc, proc->pc + 2);
	val[1] = (ocp[1] == DIR_CODE) ? get_dir2(bd, proc->pc + 4)
		: proc->r[bd->ram[MEM_MOD(proc->pc + 4)] - 1];
	val[2] = (ocp[1] == DIR_CODE) ? bd->ram[MEM_MOD(proc->pc + 6)]
		: bd->ram[MEM_MOD(proc->pc + 5)];
}

void			ldi(t_board *bd, t_process *proc)
{
	unsigned char	ocp[3];
	int				val[3];
	int				offset;

	get_ocp(bd, proc->pc + 1, ocp);
	(ocp[0] == REG_CODE) ? ldi_reg_case(bd, proc, val)
		: ldi_other_case(bd, proc, val);
	offset = calc_offset(ocp, 0);
	if (!(proc->r[bd->ram[MEM_MOD(val[2])] - 1]
			= ((proc->pc + val1 + val2) % IDX_MOD)))
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->pc += offset + 1;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLdi ", (pc + ((val1 + val2) % IDX_MOD)));
	ft_putstrnbrstr(" in r", bd->ram[proc->pc - 1], ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}

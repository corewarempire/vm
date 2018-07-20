/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:11:34 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/20 14:42:36 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_board *bd, t_process *proc)
{
	int	octal;
	int first_reg;
	int value;

	octal = ocp_scd(bd->ram[proc->pc + 1]);
	first_reg = get_reg(proc, proc->pc + 2);
	value = (octal & T_IND) ? get_indir(bd, proc->pc + 3) : get_reg(proc, proc->pc + 3);
	proc->carry = (!first_reg) ? 1 : 0;
	if (octal & T_REG)
		proc->r[value - 1] = first_reg;
	else if (octal & T_IND)
		set_ramvalue(bd, proc->pc + (value % IDX_MOD), first_reg);
	// avancer de une case pc ou de la totalite de l'info?
}
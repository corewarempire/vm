/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:10:54 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/12 10:46:15 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	ft_putstrnbrstr(char  *s, int nb, char *str)
{
	ft_putstr(s);
	ft_putnbr(nb);
	ft_putstr(str);
	return ;
}

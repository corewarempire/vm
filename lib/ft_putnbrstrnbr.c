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

void	ft_putnbrstrnbr(int nb, char *str, int n)
{
	ft_putnbr(nb);
	ft_putstr(str);
	ft_putnbr(n);
	return ;
}

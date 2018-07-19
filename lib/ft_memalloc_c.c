/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:11:02 by adhondt           #+#    #+#             */
/*   Updated: 2018/07/20 01:47:57 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

unsigned char	*ft_memalloc_c(size_t size, char c)
{
	unsigned char	*str;
	size_t	i;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	while (i != size)
		str[i++] = c;
	str[size] = '\0';
	return (str);
}

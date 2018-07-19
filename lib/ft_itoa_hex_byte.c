/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:47 by adhondt           #+#    #+#             */
/*   Updated: 2018/05/16 21:31:47 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

char	*ft_itoa_hex_byte(int value, int upper)
{
	char	*str;
	int		temp;
	int		count;

	count = 0;
	if (value == 0)
		return (ft_strdup("00"));
	temp = value;
	while (temp != 0)
	{
		count++;
		temp /= 16;
	}
	str = (char *)malloc(sizeof(char) * (count + 1 + (count == 1)));
	if (count == 1 && count++)
		str[0] = '0';
	str[count--] = '\0';
	while (value != 0)
	{
		str[count] = value % 16;
		if (upper)
			str[count] > 9 ? str[count--] += 55 : (str[count--] += '0');
		else
			str[count] > 9 ? str[count--] += 87 : (str[count--] += '0');
		value /= 16;
	}
	return (str);
}

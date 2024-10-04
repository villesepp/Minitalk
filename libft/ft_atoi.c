/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:37:48 by vseppane          #+#    #+#             */
/*   Updated: 2024/05/07 15:44:19 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_overflow(unsigned long res, int next_digit, int sign)
{
	if (res >= 922337203685477580)
	{
		if (sign == 1)
			if (next_digit > 7)
				return (-1);
		if (sign == -1)
			if (next_digit > 8)
				return (0);
	}
	if (res >= 922337203685477581)
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return (1);
}

static int	trim_spaces(const char *str, size_t i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	res;
	int				overflow;

	i = 0;
	sign = 1;
	res = 0;
	i = trim_spaces(str, i);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		overflow = if_overflow(res * 10, str[i] - 48, sign);
		if (overflow != 1)
			return (overflow);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:52:20 by vseppane          #+#    #+#             */
/*   Updated: 2024/05/06 11:29:10 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*fill;
	size_t			i;

	i = 0;
	fill = b;
	while (len > 0)
	{
		fill[i] = c;
		len--;
		i++;
	}
	return (b);
}

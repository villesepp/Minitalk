/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:50:46 by vseppane          #+#    #+#             */
/*   Updated: 2024/04/24 09:42:14 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	ret;

	ret = n;
	if (!src && !dst)
		return (dst);
	while (n--)
	{
		*(char *)dst = *(char *)src;
		src++;
		dst++;
	}
	return (dst - ret);
}

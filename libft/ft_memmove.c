/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:51:40 by vseppane          #+#    #+#             */
/*   Updated: 2024/04/25 15:25:51 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (src > dst)
	{
		while (len--)
		{
			*d = *s;
			s++;
			d++;
		}
	}
	if (src < dst)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	return (dst);
}

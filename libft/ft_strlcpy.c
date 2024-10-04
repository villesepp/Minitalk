/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:23:40 by vseppane          #+#    #+#             */
/*   Updated: 2024/05/06 11:33:50 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	if (dstsize <= 0)
		return (src_len);
	if (src_len >= dstsize)
		len = dstsize - 1;
	else
		len = src_len;
	while (len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	*dst++ = '\0';
	return (src_len);
}

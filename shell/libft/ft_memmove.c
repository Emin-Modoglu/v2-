/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:59:44 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/11 04:10:58 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*buffer1;
	char			*buffer2;

	i = len;
	buffer1 = (char *)src;
	buffer2 = (char *)dst;
	if (dst == src)
		return (dst);
	else if (buffer2 > buffer1)
	{
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (buffer2);
}

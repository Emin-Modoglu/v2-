/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:58:07 by emsakar           #+#    #+#             */
/*   Updated: 2024/03/11 02:58:07 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_cal_number_digits(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		res++;
		n = (unsigned int)n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;

	num_digits = ft_cal_number_digits(n);
	res = malloc((num_digits + 1) * sizeof(char));
	if (n == 0)
		res[0] = 48;
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[num_digits] = '\0';
	while ((num_digits - 1) >= 0 && (unsigned int)n > 0)
	{
		res[num_digits - 1] = ((unsigned int)n % 10) + '0';
		n = (unsigned int)n / 10;
		num_digits--;
	}
	return (res);
}

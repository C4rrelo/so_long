/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:25 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/10/26 17:07:16 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len += 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	unsigned int	len;
	char			*str;

	len = ft_number_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number != 0)
	{
		str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

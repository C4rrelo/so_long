/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:44:47 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/03/29 12:44:47 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int number, int *len)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar('-', len);
		ft_number(number * -1, len);
	}
	else
	{
		if (number > 9)
		{
			ft_number(number / 10, len);
		}
		ft_putchar(number % 10 + '0', len);
	}
}

void	ft_unsigned_int(unsigned int number, int *len)
{
	if (number > 9)
	{
		ft_unsigned_int(number / 10, len);
	}
	ft_putchar(number % 10 + '0', len);
}

void	ft_hexadecimal(unsigned int number, int *len, char choose)
{
	char	str[25];
	char	*hexa_base;
	int		i;

	i = 0;
	if (choose == 'X')
		hexa_base = "0123456789ABCDEF";
	else
		hexa_base = "0123456789abcdef";
	i = 0;
	if (number == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (number != 0)
	{
		str[i] = hexa_base [number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_pointer(size_t pointer, int *len)
{
	char	str[25];
	int		i;
	char	*hexa_base;

	hexa_base = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	else
		*len += write(1, "0x", 2);
	while (pointer != 0)
	{
		str[i] = hexa_base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i)
	{
		i--;
		ft_putchar(str[i], len);
	}
}

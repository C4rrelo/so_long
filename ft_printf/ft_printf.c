/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:44:34 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/03/29 12:44:34 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_check(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			print_check(string[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)string[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

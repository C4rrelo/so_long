/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:44:10 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/03/29 12:44:10 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char chr, int *len)
{
	write(1, &chr, 1);
	(*len)++;
}

void	ft_putstr(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (args == 0)
	{
		write(2, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar(args[i], len);
		i++;
	}
}

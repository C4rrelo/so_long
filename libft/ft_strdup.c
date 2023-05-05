/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:37:49 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/10/24 12:37:49 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	i = 0;
	dest = (char *)malloc(len * sizeof(char) + 1);
	ptr = dest;
	if (!ptr)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:39:05 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/10/24 12:39:05 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (s1[i + j] == '\0' && s2[j] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}

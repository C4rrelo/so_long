/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:39:14 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/10/24 12:39:14 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*home_s;
	size_t			x;

	x = 0;
	if (start >= ft_strlen(s))
	{
		home_s = (char *)malloc(sizeof(char));
		*home_s = 0;
		return (home_s);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	home_s = (char *)malloc(sizeof(*home_s) * (len + 1));
	if (!home_s)
		return (NULL);
	while (start < ft_strlen(s) && x < len)
		home_s[x++] = s[start++];
	home_s[x] = '\0';
	return (home_s);
}

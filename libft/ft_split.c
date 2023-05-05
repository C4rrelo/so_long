/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:08:08 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/10/31 15:08:08 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_letter_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	onof;
	int	word;

	i = 0;
	onof = 1;
	word = 0;
	while (s[i] != '\0')
	{
		if (onof == 1 && s[i] != c)
		{
			word++;
			onof = 0;
		}
		else if (s[i] == c)
			onof = 1;
		i++;
	}
	return (word);
}

static char	*ft_stralloc(char **strs, char const *s, int *i, char c)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_letter_count(s + *i, c) + 1));
	if (!strs || !str)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		str[j] = s[*i];
		j++;
		(*i)++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		count;

	i = 0;
	count = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			strs[count] = ft_stralloc(strs, s, &i, c);
			count++;
		}
	}
	strs[count] = 0;
	return (strs);
}

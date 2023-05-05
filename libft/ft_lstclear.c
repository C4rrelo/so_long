/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:49:42 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/11/03 14:35:08 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*hold;

	while (*lst)
	{
		hold = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = hold;
	}
	lst = NULL;
}

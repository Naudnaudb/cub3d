/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:45:51 by abordack          #+#    #+#             */
/*   Updated: 2020/05/02 15:45:52 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst && *lst)
	{
		list = *lst;
		*lst = NULL;
		while (list)
		{
			tmp = list->next;
			del(list->content);
			free(list);
			list = tmp;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:24:29 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 15:20:31 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*curr_next;

	if (!(*lst) || !(*del))
		return ;
	current = *lst;
	while (current->next)
	{
		current = *lst;
		(*del)(current->content);
		curr_next = current->next;
		free(current);
		*lst = curr_next;
	}
}

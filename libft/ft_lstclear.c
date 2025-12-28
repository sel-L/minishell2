/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:00:48 by selow             #+#    #+#             */
/*   Updated: 2025/05/20 11:20:20 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextptr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nextptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextptr;
	}
	*lst = NULL;
}

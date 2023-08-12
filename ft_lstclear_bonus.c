/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:54:37 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/13 15:00:24 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;
	t_list	*temp;

	lst2 = *lst;
	while (lst2)
	{
		temp = lst2->next;
		ft_lstdelone(lst2, del);
		lst2 = temp;
	}
	*lst = 0;
}

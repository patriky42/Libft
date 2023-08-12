/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:05:40 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/13 17:37:10 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*content;

	if (!lst)
		return (NULL);
	new = 0;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&new, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

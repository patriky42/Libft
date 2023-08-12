/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:17:18 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/05 17:39:44 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		a;
	int		z;

	a = 0;
	z = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[a] && ft_strchr(set, s1[a]))
		a++;
	while (z > a && ft_strrchr(set, s1[z]))
		z--;
	new = ft_substr((char *)s1, a, z - a + 1);
	return (new);
}

/*int	main(void)
{
	char s1 = "abcde";
	char set = "ae";
	printf("%s\n", ft_strtrim(s1, set));
			return (0);
}*/

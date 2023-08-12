/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:23:13 by pabastid          #+#    #+#             */
/*   Updated: 2022/09/29 10:42:58 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((ss1[i] == ss2[i]) && (i < n - 1))
				i++;
	return (ss1[i] - ss2[i]);
}
/*int	main(void)
{
	char s1[] = "winetime";
	char s2[] = "wine time";

	printf("%d\n", ft_memcmp(s1, s2, 8));
	return (0);
}*/

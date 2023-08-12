/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:35 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/05 18:06:34 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
	{
		size = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	m;

	size = ft_intsize(n);
	m = n;
	str = (char *)malloc(sizeof (char) * size + 1);
	if (!str)
		return (NULL);
	if (m == 0)
		str[0] = '0';
	if (m < 0)
	{
		str[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		str[size - 1] = (m % 10) + '0';
		size--;
		m = m / 10;
	}
	str[ft_intsize(n)] = '\0';
	return (str);
}
/*int	main(void)
{
	int	a = 3747961;

	printf("%s\n", ft_itoa(a));
	return (0);
}*/

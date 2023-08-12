/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:29:06 by pabastid          #+#    #+#             */
/*   Updated: 2022/10/11 12:29:34 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	num_words;

	if (ft_strlen(s) == 0)
		return (0);
	i = 0;
	num_words = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			num_words++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		num_words++;
	return (num_words);
}

static int	ft_lenwords(char const *s, int i, char c)
{
	size_t	start;

	start = (size_t)i;
	while (s[i] && s[i] != c)
		i++;
	return ((size_t)i - start);
}

static void	*ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;
	int		i;

	str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);
	word = 0;
	i = 0;
	while (word < ft_countwords (s, c) && s[i])
	{
		if (s[i] != c)
		{
			str[word] = ft_substr(s, i, ft_lenwords(s, i, c));
			if (!str[word])
				return (ft_free(str));
			i = i + ft_lenwords(s, i, c) + 1;
			word++;
		}
		else
			i++;
	}
	str[word] = 0;
	return (str);
}

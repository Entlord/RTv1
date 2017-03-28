/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:15:22 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/13 17:55:58 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_split_count(char const *s, char c)
{
	int	i;

	i = 1;
	while (*s)
	{
		if (s[0] == c && s[1] != c)
			i++;
		s++;
	}
	return (i);
}

static char	*ft_split_suppr(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nbword;
	int		i;
	size_t	lenword;
	char	**word;

	i = 0;
	nbword = ft_split_count(s, c);
	word = (char **)malloc(sizeof(char **) * nbword + 1);
	s = ft_split_suppr(s, c);
	while (*s)
	{
		if (ft_strchr(s, c) == NULL)
			lenword = (size_t)(ft_strchr(s, 0) - s);
		else
			lenword = (size_t)(ft_strchr(s, c) - s);
		word[i] = (char *)malloc(lenword + 1);
		ft_strncpy(word[i], s, lenword);
		word[i][lenword] = 0;
		s = s + lenword;
		s = ft_split_suppr(s, c);
		i++;
	}
	word[i] = 0;
	return (word);
}

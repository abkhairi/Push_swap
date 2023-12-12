/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:57:21 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/02 13:35:34 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_nbrword(const char *str, char c)
{
	size_t	i;
	size_t	counteur;
	size_t	len;

	len = ft_strlen(str);
	counteur = 0;
	i = 0;
	while (i < len)
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			counteur++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (counteur);
}

static char	**free_all(char **s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i && s[j] != NULL)
	{
		free(s[j]);
		s[j] = NULL;
		j++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **spliter, size_t wc)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (i < wc)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		spliter[i] = ft_substr(s, start, end - start);
		if (!spliter[i])
			return (free_all(spliter, i));
		start = end;
		i++;
	}
	*(spliter + i) = NULL;
	return (spliter);
}

char	**ft_split(char const *s, char c)
{
	char	**spliter;
	size_t	wc;

	if (!s)
		return (0);
	wc = ft_nbrword(s, c);
	spliter = malloc((wc + 1) * sizeof(char *));
	if (!spliter)
		return (0);
	return (ft_fill(s, c, spliter, wc));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:46:43 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/27 21:08:09 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = malloc(ft_strlen_gnl(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		c;
	int		c2;

	if (!s1)
		s1 = ft_strdup_gnl("");
	i = 0;
	c = ft_strlen_gnl(s1);
	c2 = ft_strlen_gnl(s2);
	join = (char *) malloc(c + c2 +1);
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, s1, c);
	ft_memcpy(join + c, s2, c2 + 1);
	free (s1);
	return (join);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == 0 || start >= ft_strlen_gnl(s))
		return (NULL);
	if (len > ft_strlen_gnl(s) || (start + len > ft_strlen_gnl(s)))
		len = ft_strlen_gnl(s) - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len && start < ft_strlen_gnl(s))
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

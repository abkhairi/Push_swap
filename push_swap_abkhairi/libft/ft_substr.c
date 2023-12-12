/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:20:54 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/02 11:22:45 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == 0 || start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) || (start + len > ft_strlen(s)))
		len = ft_strlen(s) - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len && start < ft_strlen(s))
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

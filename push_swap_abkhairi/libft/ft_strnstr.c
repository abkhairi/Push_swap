/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:07:21 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/01 20:08:39 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		while ((haystack[j + i] == needle[j]) && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
		j = 0;
	}
	return (0);
}

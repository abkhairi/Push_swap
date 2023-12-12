/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:26:13 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/03 13:19:13 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*trim;

	first = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *) s1);
	if (s1 == NULL && set == NULL)
		return (NULL);
	last = ft_strlen(s1);
	while (s1[first] != '\0' && ft_strchr(set, s1[first]))
		first++;
	while (last > first && ft_strchr(set, s1[last]))
		last--;
	trim = ft_substr(s1, first, (last - first) + 1);
	if (!trim)
		return (trim);
	return (trim);
}

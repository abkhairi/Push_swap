/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:42:40 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/03 13:28:39 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ds;
	size_t	ss;

	ss = ft_strlen(src);
	j = 0;
	if (dst == 0 && dstsize == 0)
		return (ss);
	ds = ft_strlen(dst);
	i = ds;
	if (dstsize == 0 || dstsize <= ds)
		return (ss + dstsize);
	while ((src[j] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ds + ss);
}

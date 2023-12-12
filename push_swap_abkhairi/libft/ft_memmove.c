/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:34:25 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/02 15:23:51 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			i;

	i = len;
	if (dst == NULL && src == NULL)
		return (NULL);
	pd = (unsigned char *) dst;
	ps = (unsigned char *) src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		while (i > 0)
		{
			pd[i - 1] = ps[i - 1];
			i--;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:31:43 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/02 15:23:28 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

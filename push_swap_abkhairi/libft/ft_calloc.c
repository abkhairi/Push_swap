/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:48 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/01 20:10:56 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	c;

	c = count * size;
	p = malloc(c);
	if (p == 0)
		return (p);
	ft_bzero(p, c);
	return (p);
}

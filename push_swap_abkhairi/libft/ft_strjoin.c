/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:11 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 19:42:09 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		c;
	int		c2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	c = ft_strlen(s1);
	c2 = ft_strlen(s2);
	join = (char *) malloc(c + c2 +1);
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, s1, c);
	ft_memcpy(join + c, s2, c2 + 1);
	return (join);
}

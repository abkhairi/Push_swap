/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:46:44 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/03 12:47:19 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	fucking_len;

	i = 0;
	fucking_len = ft_strlen(s);
	while (i <= fucking_len)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (0);
}

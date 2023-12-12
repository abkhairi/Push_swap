/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:42:59 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/03 13:18:20 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len ;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < len)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

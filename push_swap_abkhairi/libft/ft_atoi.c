/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:56 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 16:47:34 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atoi_err(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nombre;
	int		signe;

	signe = 1;
	nombre = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		nombre = nombre * 10 +(str[i] - '0');
		i++;
		if (nombre > INT_MAX)
			ft_atoi_err();
		if (nombre < INT_MIN)
			ft_atoi_err();
	}
	return ((int)nombre * signe);
}

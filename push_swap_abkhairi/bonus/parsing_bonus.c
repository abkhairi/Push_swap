/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:50:48 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 15:52:57 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_minus_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			if (i > 0 && ft_isdigit(str[i - 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_repeat(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (0);
			j++; 
		}
		i++;
	}
	return (1);
}

int	check_is_nbr(char *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	if (tab[i] == '+' || tab[i] == '-')
		i++;
	while (tab[i] != '\0')
	{
		if (!ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parsing(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (check_is_nbr(tab[i]) == 0 || check_minus_plus(tab[i]) == 0)
			errr();
		i++;
	}
	if (check_repeat(tab) == 0)
		errr();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:35:39 by abkhairi          #+#    #+#             */
/*   Updated: 2023/02/02 15:22:02 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	long	ft_count_nbr(int long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	count_nbr;
	int long	num;

	num = n;
	count_nbr = ft_count_nbr(num);
	str = malloc(sizeof(char) * count_nbr + 1);
	if (str == NULL)
		return (NULL);
	str[count_nbr] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[count_nbr - 1] = (num % 10) + 48;
		num = num / 10;
		count_nbr--;
	}
	return (str);
}

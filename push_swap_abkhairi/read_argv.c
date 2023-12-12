/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:20:47 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/03 12:21:46 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errr(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

char	*appl_join(char *s1, char *s2)
{
	int		i;
	char	*avec_espace;
	char	*result;

	i = 0;
	while (s2[i] == ' ')
		i++;
	if (s2[i] == '\0')
		errr();
	if (!s1)
		s1 = ft_strdup("");
	avec_espace = ft_strjoin(s1, " ");
	result = ft_strjoin(avec_espace, s2);
	free(s1);
	free(avec_espace);
	return (result);
}

char	*line_join(int ac, char **av)
{
	int		i;
	char	*join;

	i = 1;
	join = NULL;
	while (i < ac)
	{
		join = appl_join(join, av[i]);
		i++;
	}
	return (join);
}

char	**ft_argv(int ac, char **av)
{
	char	**tab;
	char	*join;

	join = line_join(ac, av);
	tab = ft_split((const char *)join, ' ');
	free(join);
	join = NULL;
	if (!tab)
		errr();
	return (tab);
}

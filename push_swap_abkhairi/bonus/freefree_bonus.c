/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefree_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:21:36 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 20:16:02 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_is_sorted_normal(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_tab(char **tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next_current;

	current = stack;
	while (current != NULL)
	{
		next_current = current->next;
		free(current);
		current = next_current;
	}
}

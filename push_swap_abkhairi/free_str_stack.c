/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:58:10 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 20:15:42 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

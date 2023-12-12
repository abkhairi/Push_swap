/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:28:58 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/26 17:01:55 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_min_value(t_stack *stack_a)
{
	t_stack	*min_value;
	int		min_index;

	min_index = stack_a->index;
	min_value = stack_a;
	while (stack_a)
	{
		if (stack_a->index < min_index)
		{
			min_index = stack_a->index;
			min_value = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (min_value);
}

t_stack	*find_max_value(t_stack *stack_a)
{
	int		max_index;
	t_stack	*max_value;

	max_index = stack_a->index;
	max_value = stack_a;
	while (stack_a)
	{
		if (stack_a->index > max_index)
		{
			max_index = stack_a->index;
			max_value = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (max_value);
}

int	get_ps(t_stack *stack_a, int index)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->index == index)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	calculate_size(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

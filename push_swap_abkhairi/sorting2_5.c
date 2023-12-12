/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:27:07 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/26 17:00:06 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nbr(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sort_3_nbr(t_stack **stack_a)
{
	int	first;
	int	second;
	int	final;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	final = (*stack_a)->next->next->data;
	if ((second < first && second < final) && final > first)
		sort_2_nbr(&(*stack_a));
	else if (first > second && final > second)
		ra(stack_a);
	else if (first > second && second > final && first > final)
	{
		sort_2_nbr(&(*stack_a));
		rra(stack_a);
	}
	else if (second > first && second > final && final > first)
	{
		sort_2_nbr(&(*stack_a));
		ra(stack_a);
	}
	else if (second > first && second > final && final < first)
		rra(stack_a);
}

void	sort_4_nbr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_val;
	int		pos;

	min_val = find_min_value(*stack_a);
	pos = get_ps(*stack_a, min_val->index);
	if (pos == 1)
	{
		ra(stack_a);
	}
	else if (pos == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3_nbr(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5_nbr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_val;
	int		pos;

	min_val = find_min_value(*stack_a);
	pos = get_ps(*stack_a, min_val->index);
	if (pos == 1)
	{
		ra(stack_a);
	}
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_4_nbr(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:24:20 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 16:33:49 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_top(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && get_ps(*stack_b, find_max_value(*stack_b)->index)
		<= calculate_size(*stack_b) / 2)
	{
		if (*stack_b && get_ps(*stack_b, find_max_value(*stack_b)->index - 1)
			< get_ps(*stack_b, find_max_value(*stack_b)->index))
		{
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index - 1)
				rb(stack_b);
			pa(stack_a, stack_b);
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index)
				rb(stack_b);
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
		{
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index)
				rb(stack_b);
		}
	}
}

void	algo_bottom(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && get_ps(*stack_b, find_max_value(*stack_b)->index)
		> calculate_size(*stack_b) / 2)
	{
		if (*stack_b && get_ps(*stack_b, find_max_value(*stack_b)->index - 1)
			> get_ps(*stack_b, find_max_value(*stack_b)->index))
		{
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index - 1)
				rrb(stack_b);
			pa(stack_a, stack_b);
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index)
				rrb(stack_b);
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
		{
			while (*stack_b && (*stack_b)->index 
				!= find_max_value(*stack_b)->index)
				rrb(stack_b);
		}
	}
}

void	push_and_rr_or_rb(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int	tmp_chunk;

	tmp_chunk = chunks;
	pb(stack_a, stack_b);
	if (*stack_a && (*stack_a)->index > tmp_chunk)
		rr(stack_a, stack_b);
	else if (*stack_a && (*stack_a)->index < tmp_chunk)
		rb(stack_b);
}

void	push_a_to_b_shema(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int	nos;
	int	premierchunk;

	premierchunk = chunks;
	nos = chunks / 2;
	while (*stack_a)
	{
		while (*stack_a && search_index(*stack_a, chunks) == 1)
		{
			if (*stack_a && (*stack_a)->index < chunks)
			{
				if (*stack_a && (*stack_a)->index < nos)
					push_and_rr_or_rb(stack_a, stack_b, chunks);
				else
					pb(stack_a, stack_b);
			}
			else
				ra(stack_a);
		}
		nos = ((chunks * 2) + premierchunk) / 2;
		chunks += premierchunk;
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunks;
	int	sizet;

	sizet = 0;
	if (stack_a == NULL)
		exit(1);
	if (size <= 100)
		sizet = size / 5;
	else if (size <= 500)
		sizet = size / 10;
	chunks = sizet;
	push_a_to_b_shema(stack_a, stack_b, chunks);
	while (*stack_b)
	{
		if (*stack_b && (*stack_b)->index == find_max_value(*stack_b)->index)
		{
			pa(stack_a, stack_b);
			size--;
		}
		else
		{
			algo_top(stack_a, stack_b);
			algo_bottom(stack_a, stack_b);
		}
	}
}

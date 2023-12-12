/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:18:00 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/04 11:18:15 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_node_before_last(t_stack *stack_a)
{
	t_stack	*prev;
	t_stack	*current;

	if (stack_a == NULL || stack_a->next == NULL)
	{
		return (NULL);
	}
	current = stack_a;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	return (prev);
}

void	rra(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*before_last_node;

	curr = *stack_a;
	if (!curr)
		exit(1);
	while (curr->next != NULL)
		curr = curr->next;
	before_last_node = find_node_before_last(*stack_a);
	before_last_node->next = NULL;
	curr->next = *stack_a;
	*stack_a = curr;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*curr;
	t_stack	*before_last_node;

	curr = *stack_b;
	if (!curr)
		exit(1);
	while (curr->next != NULL)
		curr = curr->next;
	before_last_node = find_node_before_last(*stack_b);
	before_last_node->next = NULL;
	curr->next = *stack_b;
	*stack_b = curr;
	write(1, "rrb\n", 4);
}

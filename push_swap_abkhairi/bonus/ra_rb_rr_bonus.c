/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:16:24 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 15:54:42 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*get_last_node(t_stack **stack_a)
{
	t_stack	*last_node;

	last_node = *stack_a;
	if (!last_node)
		exit(1);
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

void	rotation(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*fnode;

	fnode = *stack;
	curr = get_last_node(&(*stack));
	*stack = (*stack)->next;
	curr->next = fnode;
	fnode->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotation(stack_a);
}

void	rb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotation(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotation(stack_a);
	rotation(stack_b);
}

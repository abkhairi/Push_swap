/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:14:38 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 15:56:07 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack **stack_a)
{
	int	tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
}

void	sa(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a || *stack_b) && !((*stack_a)->next || !(*stack_b)->next))
		return ;
	sa(stack_a);
	sb(stack_b);
}

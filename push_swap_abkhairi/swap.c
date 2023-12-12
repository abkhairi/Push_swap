/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:02:05 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/26 17:00:56 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
}

void	sa(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

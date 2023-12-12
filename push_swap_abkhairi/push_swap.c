/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:31:31 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/03 13:43:20 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nbr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 2)
		sort_2_nbr(&(*stack_a));
	else if (i == 3)
		sort_3_nbr(&(*stack_a));
	else if (i == 4)
		sort_4_nbr(&(*stack_a), &(*stack_b));
	else if (i == 5)
		sort_5_nbr(&(*stack_a), &(*stack_b));
	else if (i >= 6)
		big_sort(&(*stack_a), &(*stack_b), i);
}

int	count_ac(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	main(int argc, char **av)
{
	char	**tab;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	tab = ft_argv(argc, av);
	parsing(tab);
	i = 0;
	while (tab[i])
	{
		put_argv(&stack_a, ft_atoi(tab[i]));
		i++;
	}
	free_tab(tab, count_ac(tab));
	indexing(stack_a, i);
	if (ft_is_sorted_normal(stack_a) == 1)
		exit(0);
	else if (ft_is_sorted_normal(stack_a) == 0)
		sort_nbr(&stack_a, &stack_b, i);
	free_stack(stack_a);
	free_stack(stack_b);
}

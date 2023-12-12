/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:18:00 by abkhairi          #+#    #+#             */
/*   Updated: 2023/11/03 13:45:55 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort1( t_stack **stack_a, t_stack **stack_b, char *action)
{
	if (!ft_strncmp("sa", action, 2))
		sa(stack_a);
	else if (!ft_strncmp("sb", action, 2))
		sb(stack_b);
	else if (!ft_strncmp("ss", action, 2))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("pa", action, 2))
		pa(stack_a, stack_b);
	else if (!ft_strncmp("pb", action, 2))
		pb(stack_a, stack_b);
	else if (!ft_strncmp("ra", action, 2))
		ra(stack_a);
	else if (!ft_strncmp("rb", action, 2))
		rb(stack_b);
	else if (!ft_strncmp("rr", action, 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("rra", action, 3))
		rra(stack_a);
	else if (!ft_strncmp("rrb", action, 3))
		rrb(stack_b);
	else if (!ft_strncmp("rrr", action, 3))
		rrr(stack_a, stack_b);
	else
		errr();
}

void	sort_no_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && ft_is_sorted_normal(*stack_a) && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*stack_a);
	free_stack(*stack_b);
}

int	count_ac(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tab;
	char	*action;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(0);
	tab = ft_argv(ac, av);
	parsing(tab);
	i = -1;
	while (tab[++i])
		put_argv(&stack_a, ft_atoi(tab[i]));
	free_tab(tab, count_ac(tab));
	while (1)
	{
		action = get_next_line(STDIN_FILENO);
		if (action == NULL)
			break ;
		sort1(&stack_a, &stack_b, action);
		free(action);
	}
	sort_no_sort(&stack_a, &stack_b);
}

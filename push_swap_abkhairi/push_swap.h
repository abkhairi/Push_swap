/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:29:55 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 16:27:40 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	errr(void);
char	*appl_join(char *s1, char *s2);
char	**ft_argv(int ac, char **av);
int		check_repeat(char **tab);
int		check_is_nbr(char *tab);
int		check_minus_plus(char *str);
void	parsing(char **tab);
int		ft_is_sorted_normal(t_stack *stack);
void	afficherlist(t_stack *head);
t_stack	*create_new_node(int value);
void	put_argv(t_stack **head, int value);
t_stack	*get_last_node(t_stack **stack_a);
int		calculate_size(t_stack *stack);

void	swap(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);

void	free_tab(char **tab, int ac);
void	free_stack(t_stack *stack);

void	sort_2_nbr(t_stack **stack_a);
void	sort_3_nbr(t_stack **stack_a);
void	sort_4_nbr(t_stack **stack_a, t_stack **stack_b);
void	sort_5_nbr(t_stack **stack_a, t_stack **stack_b);
void	big_sort(t_stack **stack_a, t_stack **stack_b, int size);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

void	indexing(t_stack *stack_a, int len);
int		search_index(t_stack *stack_a, int group);

t_stack	*find_min_value(t_stack *stack_a);
t_stack	*find_max_value(t_stack *stack_a);
int		get_ps(t_stack *stack_a, int index);

void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
#endif
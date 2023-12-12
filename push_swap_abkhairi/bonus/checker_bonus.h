/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:02:06 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 15:52:15 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack {
	int				data;
	struct s_stack	*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	errr(void);
char	*appl_join(char *s1, char *s2);
char	**ft_argv(int ac, char **av);
int		check_repeat(char **tab);
int		check_is_nbr(char *tab);
int		check_minus_plus(char *str);
void	parsing(char **tab);
int		ft_is_sorted_normal(t_stack *stack);
t_stack	*create_new_node(int value);
void	put_argv(t_stack **head, int value);
t_stack	*get_last_node(t_stack **stack_a);
int		calculate_size(t_stack *stack);
char	*get_next_line(int fd);

void	swap(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	free_tab(char **tab, int ac);
void	free_stack(t_stack *stack);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
#endif
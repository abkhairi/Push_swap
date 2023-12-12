/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:32:20 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/31 16:27:16 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_arry(t_stack *stack_a, int len)
{
	int	*arry;
	int	i;

	arry = (int *)malloc(len * sizeof(int));
	if (!arry)
		return (0);
	i = 0;
	while (i < len)
	{
		arry[i] = stack_a->data;
		i++;
		stack_a = stack_a->next;
	}
	return (arry);
}

int	*bbule(int *arr, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	tmp = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	indexing(t_stack *stack_a, int len)
{
	int	*arr;
	int	i;

	i = 0;
	if (stack_a == NULL)
		return ;
	arr = create_arry(stack_a, len);
	arr = bbule(arr, len);
	while (stack_a)
	{
		i = 0;
		while (i < len)
		{
			if (stack_a->data == arr[i])
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
	free(arr);
}

int	search_index(t_stack *stack_a, int group)
{
	while (stack_a)
	{
		if (stack_a->index < group)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

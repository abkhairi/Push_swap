/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:17:47 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/26 17:18:45 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->data = value;
	newnode->next = NULL;
	return (newnode);
}

void	put_argv(t_stack **head, int value)
{
	t_stack	*current;

	current = *head;
	if (*head == NULL)
		*head = create_new_node(value);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = create_new_node(value);
	}
}

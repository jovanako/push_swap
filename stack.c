/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:09:17 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/12 12:55:21 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_empty(t_stack *stack)
{
	if (stack->head == NULL)
		return (1);
	return (0);
}

int	stack_size(t_stack *stack)
{
	int			count;
	t_list_node	*current_node;

	current_node = stack->head;
	count = 0;
	while (current_node)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

int	push(t_stack *stack, int n)
{
	t_list_node	*node;

	node = new_node(n);
	if (!node)
		return (0);
	if (stack->tail == NULL)
		stack->tail = node;
	add_front(&(stack->head), node);
	return (1);
}

int	pop(t_stack *stack)
{
	return (remove_front(&(stack->head)));
}

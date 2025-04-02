/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:09:17 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/02 20:43:55 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *create_stack()
{
    t_stack *new_stack;

    new_stack = (t_stack *)malloc(sizeof(t_stack));
    new_stack->head = NULL;
    new_stack->tail = NULL;
    return (new_stack);
}

int    push(t_stack *stack, int n)
{
    t_list_node *node;
    
    node = new_node(n);
    if (!node)
        return (0);
    if (stack->tail == NULL)
        stack->tail = node;
    add_front(&(stack->head), node);
    return (1);
}

int     pop(t_stack *stack)
{
    return (remove_front(&(stack->head)));
}
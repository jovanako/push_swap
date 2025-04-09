/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 20:28:46 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int    rotate(t_stack *stack)
{
    int         value;
    t_list_node *node;

    if (is_empty(stack))
        return (1);
    value = pop(stack);
    node = new_node(value);
    if (!node)
        return (0);
    add_back(&(stack->tail), node);
    return(1);    
}

int    rr(t_stack *a, t_stack *b)
{
    if (is_empty(a) || is_empty(b))
        return (1);
    if (!rotate(a) || !rotate(b))
        return (0);
    return (1);
}

int    rev_rotate(t_stack *stack)
{
    int         value;
    t_list_node *previous_node;

    if (is_empty(stack))
        return (1);
    previous_node = stack->head;
    while (previous_node)
    {
        if (previous_node->next == stack->tail)
            break ;
        previous_node = previous_node->next;
    }
    value = remove_back(&(stack->tail));
    previous_node->next = NULL;
    if (!push(stack, value))
        return (0);
    return (1);
}

int    rrr(t_stack *a, t_stack *b)
{
    if (is_empty(a) || is_empty(b))
        return (1);
    if (!rev_rotate(a) || !rev_rotate(b))
        return (0);
    return (1);
}
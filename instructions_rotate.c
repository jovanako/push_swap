/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/02 21:26:54 by jkovacev         ###   ########.fr       */
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

    if (is_empty(stack))
        return (1);
    value = remove_back(&(stack->tail));
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
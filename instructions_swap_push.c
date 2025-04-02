/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:34:45 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/02 20:25:00 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int     is_empty(t_stack *stack)
{
    if (stack->head == NULL)
        return (1);
    return (0);
}

int    swap_first_two(t_stack *stack)
{
    int         value1;
    int         value2;

    if (is_empty(stack) || stack->head->next != NULL)
        return (1);
    value1 = pop(stack);
    value2 = pop(stack);
    if (!push(stack, value1))
        return (0);
    if (!push(stack, value2))
        return (0);
    return (1);
}

int    ss(t_stack *a, t_stack *b)
{
    if (is_empty(a) || is_empty(b))
        return (1);
    if (!swap_first_two(a) || !swap_first_two(b))
        return (0);
    return (1);
}

int    push_to_other(t_stack *dest, t_stack *src)
{
    int     value;

    if (is_empty(dest))
        return (1);
    value = pop(src);
    if (!push(dest, value))
        return (0);
    return (1);
    return (0);
}
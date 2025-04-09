/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:34:45 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 21:56:46 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int    swap_first_two(t_stack *stack)
{
    int         value1;
    int         value2;

    if (is_empty(stack) || stack->head->next == NULL)
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

    if (is_empty(src))
        return (1);
    value = pop(src);
    if (!push(dest, value))
        return (0);
    return (1);
}
#include <stdio.h>
void    print_stack(t_stack *stack, char c)
{
    int i = 1;
    t_list_node *current_node = stack->head;
    while (current_node)
    {
            printf("stack%c%d: %d\n", c, i, current_node->number);
            current_node = current_node->next;
            i++;
    }
    printf("\n");
}
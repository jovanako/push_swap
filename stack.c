/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:09:17 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/31 22:43:33 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack    *create_stack()
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

int    fill_stack(t_stack *stack, int n, char *nums[])
{
    int         i;
    
    i = n - 1;
    while (i > 0)
    {
        if (!push(stack, ft_atoi(nums[i])))
            return (0);
        i--;
    }
    return (1);
}
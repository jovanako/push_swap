/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:39:52 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/11 18:51:26 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int      sorted(t_stack *stack)
{
    t_list_node *current_node;
    int         sorted;

    sorted = 1;
    current_node = stack->head;
    while (current_node->number != stack->tail->number)
    {
        if (current_node->number > current_node->next->number)
            sorted = 0;
        current_node = current_node->next;
    }
    return (sorted);
}

int     sort(int n, t_stack *a, t_stack *b)
{
    int     size;
    int     max;

    size = stack_size(a);
    max = size - 1;
    if (size < 4)
    {
        if (!sort_three_nums(a, max))
            return (0);
    }
    else if (size < 6)
    {
        if (!sort_five_nums(a, b, max))
            return (0);
    }
    else
        r_sort(n, a, b);
    return (1);
}
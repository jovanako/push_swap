/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:00:48 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/11 18:43:05 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int     sort_max_end(t_stack *a, t_list_node *middle_node)
{
    if (a->tail->number > middle_node->number)
    {
        write (1, "ra\n", 3);
        if (!rotate(a))
            return (0);
    }
    else
    {
        write (1, "ra\n", 3);
        if (!rotate(a))
            return (0);
        write (1, "sa\n", 3);
        if (!swap_first_two(a))
            return (0);
        }
    return (1);
}

static int     sort_max_middle(t_stack *a)
{
    if (a->tail->number < a->head->number)
    {
        write (1, "rra\n", 4);
        if (!rev_rotate(a))
            return (0);
    }
    else
    {
        write (1, "sa\n", 3);
        if (!swap_first_two(a))
            return (0);
        write (1, "ra\n", 3);
        if (!rotate(a))
            return (0);
        }
    return (1);
}

int     sort_three_nums(t_stack *a, int max)
{
    t_list_node *middle_node;

    middle_node = a->head->next;
    if (a->head->number < middle_node->number
            && middle_node->number < a->tail->number)
            return (1);
    if (a->head->number == max)
    {
        if (!sort_max_end(a, middle_node))
            return (0);
    }
    else if (middle_node->number == max)
    {
        if (!sort_max_middle(a))
            return (0);
    }
    else
    {
        write (1, "sa\n", 3);
        if (!swap_first_two(a))
            return (0);
    }
    return (1);
}

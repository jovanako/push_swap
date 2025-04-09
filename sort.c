/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:24 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 16:10:54 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int     count_bits_highest(int n)
{
    int             count;

    count = 0;
    while (n > 0)
    {
        count++;
        n >>= 1;
    }
    return (count);
}

void     add_simple_nums(t_stack *stack, int *arr, int len)
{
    int         i;
    t_list_node *current_node;

    current_node = stack->head;
    while (current_node)
    {
        i = 0;
        while (i < len)
        {
            if (current_node->number == arr[i])
            {
                current_node->simple = i;
                break ;
            }
            i++;
        }
        current_node = current_node->next;
    }
}


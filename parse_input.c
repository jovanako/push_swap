/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:11:00 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/03 17:34:25 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int     check_digit(char *s)
{
    int     i;

    i = 0;
    if (s[i] == '-')
        i = 1;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
        i++;
    }
	return (1);
}
static int     is_duplicate(t_list_node *node, int n)
{
    int         current_num;
    t_list_node *current_node;

    current_node = node;
    if (current_node)
    {
        current_num = current_node->number;
        while (current_node->next)
        {
            if (current_num == n)
                return (1);
            current_node = current_node->next;
            current_num = current_node->number;
        }
    }
    return (0);
}
#include <stdio.h>
int    fill_stack(t_stack *stack, int n, char *nums[])
{
    int     i;
    int     current_value;
    // int     previous;
    
    i = n;
    while (i > 0)
    {
        if (!check_digit(nums[i]))
        {
            write (1, "Error\nSome arguments are not integers.\n", 39);
            return (0);
        }
        current_value = ft_atoi(nums[i]);
        if (!push(stack, current_value))
            return (0);
        if (is_duplicate(stack->head, current_value))
        {
            write (1, "Error\nSome arguments are duplicates.\n", 37);
            return (0);
        }
        i--;
    }
    return (1);
}

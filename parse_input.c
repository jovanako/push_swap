/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:11:00 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/08 15:47:40 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int     find_highest_number(t_stack *stack)
{
    int         i;
    int         distance_max;
    int         current_value;
    int         max;
    t_list_node *current_node;

    current_node = stack->head;
    max = INT_MIN;
    i = 0;    
    while (current_node)
    {
        current_value = current_node->number;
        if (current_value > max)
        {
            max = current_value;
            distance_max = i;
        }
        current_node = current_node->next;
        i++;
    }
    return (distance_max);
}

static int     check_digit(char *s)
{
    int     i;

    i = 0;
    if (s[i] == '-')
        i = 1;
    if (s[i] == '0')
        return (1);
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            write (1, "Error\nSome arguments are not integers.\n", 39);
            return (0);
        }
        i++;
    }
	return (1);
}
static int     is_duplicate(t_list_node *node, int n)
{
    int         current_num;
    t_list_node *current_node;

    current_node = node;
    while (current_node)
    {
        current_num = current_node->number;
		if (current_num == n)
        {
            write (1, "Error\nSome arguments are duplicates.\n", 37);
			return (1);
        }
		current_node = current_node->next;
    }
    return (0);
}

int    fill_stack(t_stack *stack, int n, char *nums[])
{
    int     i;
    int     current_value;
    int     sorted;
    
    i = n;
    sorted = 1;
    while (i > 0)
    {
        if (!check_digit(nums[i]))
            return (0);
        current_value = ft_atoi(nums[i]);
        if (is_duplicate(stack->head, current_value))
            return (0);
        if (sorted && !is_empty(stack) && current_value > stack->head->number)
            sorted = 0;
        if (!push(stack, current_value))
            return (0);
        i--;
    }
    if (sorted == 1)
        exit(0);
    return (1);
}

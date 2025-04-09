/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:25 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 17:37:59 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

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
    
    i = n;
    while (i > 0)
    {
        if (!check_digit(nums[i]))
            return (0);
        current_value = ft_atoi(nums[i]);
        if (is_duplicate(stack->head, current_value))
            return (0);
        if (!push(stack, current_value))
            return (0);
        i--;
    }
    return (1);
}

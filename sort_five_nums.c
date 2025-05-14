/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:35:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:57 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	find_min(t_stack *stack, int min)
{
	int			distance;
	t_list_node	*current_node;

	if (stack->head->number == min)
		return (0);
	distance = 0;
	current_node = stack->head->next;
	while (current_node)
	{
		distance++;
		if (current_node->number == min)
			break ;
		current_node = current_node->next;
	}
	return (distance);
}

static int	rotate_min(t_stack *a, int min, int distance, int mid)
{
	if (distance < mid)
	{
		while (a->head->number != min)
		{
			write (1, "ra\n", 3);
			if (!rotate(a))
				return (0);
		}
	}
	else
	{
		while (a->head->number != min)
		{
			write (1, "rra\n", 4);
			if (!rev_rotate(a))
				return (0);
		}
	}
	return (1);
}

static int	sort_two_mins(t_stack *a, t_stack *b)
{
	int	min;
	int	distance;

	min = 0;
	distance = find_min(a, min);
	if (distance != 0)
	{
		if (!rotate_min(a, min, distance, 3))
			return (0);
	}
	write (1, "pb\n", 3);
	if (!push_to_other(b, a))
		return (0);
	min += 1;
	distance = find_min(a, min);
	if (distance != 0)
	{
		if (!rotate_min(a, min, distance, 2))
			return (0);
	}
	write (1, "pb\n", 3);
	if (!push_to_other(b, a))
		return (0);
	return (1);
}

int	sort_five_nums(t_stack *a, t_stack *b, int max)
{
	int	i;

	if (!sort_two_mins(a, b))
		return (0);
	if (!sorted(a))
	{
		if (!sort_three_nums(a, max))
			return (0);
	}
	i = 2;
	while (i > 0)
	{
		write (1, "pa\n", 3);
		if (!push_to_other(a, b))
			return (0);
		i--;
	}
	return (1);
}

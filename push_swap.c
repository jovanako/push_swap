/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/12 22:20:51 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	cleanup(t_stack *stack)
{
	t_list_node	*current_node;
	t_list_node	*temp;

	current_node = stack->head;
	while (current_node)
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
	free(stack);
}

int     main(int argc, char *argv[])
{
    t_stack         *a;
    t_stack         *b;
    int             *arr;

    if (argc == 1)
        return (0);
    if (!parse_args(&arr, argc, argv))
        return (1);
    a = create_stack();
    if (!a)
        return (1);
    b = create_stack();
    if (!b)
        return (1);
    sort_arr(arr, argc - 1);
    if (!arr)
        return (0);
    if (!fill_stack(a, arr, argc - 1, argv))
        return (1);
    if (!sort(argc - 2, a, b))
        return (1);
    free(arr);
	cleanup(a);
	cleanup(b);
    return (0);
}

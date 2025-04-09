/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 16:15:29 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"
#include <stdio.h>

int     main(int argc, char *argv[])
{
    t_stack         *a;
    t_stack         *b;
    int             *arr;

    a = create_stack();
    if (!a)
        return (1);
    b = create_stack();
    if (!b)
        return (1);
    if (!fill_stack(a, argc - 1, argv))
        return (1);
    arr = sort_arr(argc, argv);
    if (!arr)    
        return (0);
    // int i = 0;
    // while (i < (argc - 1))
    // {
    //     printf("arr[%d]: %d\n", i, arr[i]);
    //     i++;
    // }
    add_simple_nums(a, arr, argc - 1);
    // i = 1;
    // t_list_node *current_node = a->head;
    // while (current_node)
    // {
    //         printf("a%d: %d simple: %d\n", i, current_node->number, current_node->simple);
    //         current_node = current_node->next;
    //         i++;
    // }
    r_sort(argc - 2, a, b);
    free(arr);
    return (0);
}

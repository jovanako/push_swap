/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 20:34:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"
#include <stdio.h>

int     main(int argc, char *argv[])
{
    t_stack         *a;
    t_stack         *b;
    int             *arr;

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
    // int i = 0;
    // while (i < (argc - 1))
    // {
    //     printf("arr[%d]: %d\n", i, arr[i]);
    //     i++;
    // }
    // i = 1;
    // t_list_node *current_node = a->head;
    // while (current_node)
    // {
    //         printf("a%d: %d\n", i, current_node->number);
    //         current_node = current_node->next;
    //         i++;
    // }
    r_sort(argc - 2, a, b);
    // current_node = a->head;
    // i = 1;
    // while (current_node)
    // {
    //         printf("a%d: %d\n", i, current_node->number);
    //         current_node = current_node->next;
    //         i++;
    // }
    free(arr);
    return (0);
}

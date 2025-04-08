/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:16:55 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/08 14:38:21 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int     main(int argc, char *argv[])
{
    t_stack         *a;
    t_stack         *b;

    a = create_stack();
    if (!a)
        return (1);
    b = create_stack();
    if (!b)
        return (1);
    if (!fill_stack(a, argc - 1, argv))
        return (1);
    // t_list_node *current_node = a->head;
    // int i = 1;
    // while (current_node)
    // {
    //     printf("a%d: %d\n", i, current_node->number);
    //     current_node = current_node->next;
    //     i++;
    // }
    r_sort(a, b);
    // printf("\nsorted\n");
    // current_node = a->head;
    // i = 1;
    // while (current_node)
    // {
    //     printf("a%d: %d\n", i, current_node->number);
    //     current_node = current_node->next;
    //     i++;
    // }
    // printf("\n");
    // current_node = b->head;
    // i = 1;
    // while (current_node)
    // {
    //     printf("b%d: %d\n", i, current_node->number);
    //     current_node = current_node->next;
    //     i++;
    // }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:16:55 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/05 14:31:03 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int     main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    a = create_stack();
    if (!a)
        return (1);
    b = create_stack();
    if (!b)
        return (1);
    fill_stack(a, argc - 1, argv);
    return (0);
}
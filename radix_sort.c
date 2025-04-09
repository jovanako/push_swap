/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:22:41 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 16:20:19 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static int     sort_bit(t_stack *a, t_stack *b, int mask)
{
    int     size;

    size = stack_size(a);
    while (size > 0)
    {
        if ((a->head->simple & mask) == 0)
        {
            write (1, "pb\n", 3);
            if (!push_to_other(b, a))
                return (0);
        }
        else
        {
            write (1, "ra\n", 3);
            if(!rotate(a))
                return (0);
        }
        size--;        
    }
    return (1);
}

static int     sort_negatives(t_stack *stack, int mask)
{
    int    size;
    
    size = stack_size(stack);
    while (size > 0)
    {
        if ((stack->head->simple & mask) == 0)
        {
            write (1, "ra\n", 3);
            if(!rotate(stack))
                return (0);
        }
        size--;
    }
    return (1);
}

static int     refill_a(t_stack *a, t_stack *b)
{
    int     size;

    size = stack_size(b);
    while (size > 0)
    {
        write (1, "pa\n", 3);
        if (!push_to_other(a, b))
            return (0);
        size--;
    }
    return (1);

}

int     r_sort(int n, t_stack *a, t_stack *b)
{
    int     mask;
    int     bit;
    int     bit_count;

    mask = 1;
    bit = count_bits_highest(n);
    bit_count = 0;
    while (bit_count < (bit - 1))
    {
        if (!sort_bit(a, b, mask))
            return (0);
        if (!refill_a(a, b))
            return (0);
        mask <<= 1;
        bit_count++;
    }
    if (!sort_negatives(a, mask))
        return (0);
    return (1);
}
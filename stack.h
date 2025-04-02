/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:42:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/02 20:45:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

typedef struct s_stack
{
    t_list_node *head;
    t_list_node *tail;
}   t_stack;

int         fill_stack(t_stack *stack, int n, char *nums[]);
t_stack     *create_stack();
int         ft_atoi(char *nptr);
char	*ft_itoa(int n);
int         is_empty(t_stack *stack);
int         swap_first_two(t_stack *stack);
int         ss(t_stack *a, t_stack *b);
int         push(t_stack *stack, int n);
int         push_to_other(t_stack *dest, t_stack *src);
int         pop(t_stack *stack);
int         rotate(t_stack *stack);
int         rr(t_stack *a, t_stack *b);
int         rev_rotate(t_stack *stack);
int         rrr(t_stack *a, t_stack *b);
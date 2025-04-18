/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:58 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 09:58:25 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

typedef struct s_stack
{
    t_list_node *head;
    t_list_node *tail;
}   t_stack;

int     is_empty(t_stack *stack);
int     stack_size(t_stack *stack);
t_stack *create_stack();
int     push(t_stack *stack, int n);
int     pop(t_stack *stack);
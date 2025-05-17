/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:58 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/16 11:55:28 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "list.h"

typedef struct s_stack
{
	t_list_node	*head;
	t_list_node	*tail;
}	t_stack;

int		is_empty(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*create_stack(void);
int		push(t_stack *stack, int n);
int		pop(t_stack *stack);

#endif

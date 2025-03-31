/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:42:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/31 21:45:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

typedef struct s_stack
{
    t_list_node *head;
    t_list_node *tail;
}   t_stack;

t_stack fill_stack(t_stack **stack, int n, char *nums[]);
int	    ft_atoi(char *nptr);
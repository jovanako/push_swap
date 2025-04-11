/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:58 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/11 18:51:41 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void    sort_arr(int *arr, int len);
int     sort_three_nums(t_stack *a, int max);
int     sort_five_nums(t_stack *a, t_stack *b, int max);
int     sort(int n, t_stack *a, t_stack *b);
int     r_sort(int n, t_stack *a, t_stack *b);
int     sorted(t_stack *stack);
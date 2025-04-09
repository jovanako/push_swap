/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 16:15:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int     ft_atoi(char *nptr);
char	*ft_itoa(int n);
int     fill_stack(t_stack *stack, int n, char *nums[]);
int     *sort_arr(int n, char *nums[]);
int     count_bits_highest(int n);
void    add_simple_nums(t_stack *stack, int *arr, int len);
int     r_sort(int n, t_stack *a, t_stack *b);
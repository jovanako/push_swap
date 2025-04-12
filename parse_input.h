/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/12 22:14:14 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int     ft_atoi(char *nptr, int *arr);
char	*ft_itoa(int n);
int     parse_args(int **arr, int argc, char *argv[]);
int     fill_array(int **arr, int n, char *nums[]);
int     fill_stack(t_stack *stack, int *arr, int n, char *nums[]);
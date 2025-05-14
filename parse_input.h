/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:50 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/14 17:23:59 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
#define PARSE_INPUT_H

#include "stack.h"

typedef struct s_arr
{
	char	**numbers;
	int		*arr;
	int		size;
}	t_arr;


int		ft_atoi(char *s, t_arr *arr_nums);
int		valid_str(char *s);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int		count_words(char *s, char c);
char	**ft_split(char *s, char c);
int		parse_args(t_arr **arr_nums, int argc, char *argv[]);
int		fill_array(t_arr **arr_nums, char *nums[]);
int		fill_stack(t_stack *stack, t_arr *arr_nums);
int		check_digit(char *s);
int		error_and_return(void);
int		free_t_arr_and_return(t_arr *arr_nums);
void	free_full_t_arr(t_arr *arr_nums);
int		free_full_t_arr_and_return(t_arr *arr_nums);

#endif
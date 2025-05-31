/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:26 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/31 17:45:53 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static char	*ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while (size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (dst);
}

char	**copy_numbers(int n, char *src[], char *dst[])
{
	int	i;
	int	j;
	int	len;

	dst = (char **)malloc(n * sizeof(char *));
	if (!dst)
		return (0);
	i = 1;
	j = 0;
	while (i < n)
	{
		len = ft_strlen(src[i]);
		dst[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!dst)
			return (0);
		dst[j] = ft_strlcpy(dst[j], src[i], len + 1);
		i++;
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

static int	check_dup(t_arr *arr_nums)
{
	int	i;
	int	j;

	i = 0;
	while (i < (arr_nums->size))
	{
		j = i + 1;
		while (j < (arr_nums->size))
		{
			if (arr_nums->arr[i] == arr_nums->arr[j])
			{
				write (2, "Error\n", 6);
				return (free_full_t_arr_and_return(arr_nums));
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_args(t_arr **arr_nums, int argc, char *argv[])
{
	(*arr_nums) = ((t_arr *)malloc(sizeof(t_arr)));
	if (!(*arr_nums))
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		(*arr_nums)->numbers = ft_split(argv[1], ' ');
		if (!(*arr_nums)->numbers)
			return (free_t_arr_and_return(*arr_nums));
		(*arr_nums)->size = count_words(argv[1], ' ');
	}
	else if (argc > 2)
	{
		(*arr_nums)->size = argc - 1;
		(*arr_nums)->numbers = copy_numbers(argc, argv, (*arr_nums)->numbers);
		if (!(*arr_nums)->numbers)
			return (free_t_arr_and_return(*arr_nums));
	}
	if (!fill_array(arr_nums, (*arr_nums)->numbers))
		return (free_full_t_arr_and_return(*arr_nums));
	if (!check_dup(*arr_nums))
		return (0);
	return (1);
}

int	fill_stack(t_stack *stack, t_arr *arr_nums)
{
	int	i;
	int	j;
	int	current_value;

	i = arr_nums->size - 1;
	while (i >= 0)
	{
		current_value = ft_atol(arr_nums->numbers[i]);
		j = 0;
		while (j < arr_nums->size)
		{
			if (current_value == arr_nums->arr[j])
			{
				if (!push(stack, j))
					return (0);
				break ;
			}
			j++;
		}
		i--;
	}
	return (1);
}

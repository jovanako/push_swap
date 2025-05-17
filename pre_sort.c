/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:08:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/17 21:43:52 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	check_digit(char *s, t_arr *arr_nums)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i = 1;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			free_full_t_arr(arr_nums);
			write (2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	fill_array(t_arr **arr_nums, char *nums[])
{
	int			i;
	long int	number;

	(*arr_nums)->arr = (int *)malloc((*arr_nums)->size * sizeof(int));
	if (!((*arr_nums)->arr))
		return (0);
	i = 0;
	while ((i < (*arr_nums)->size) && check_digit(nums[i], *arr_nums))
	{
		number = ft_atol(nums[i]);
		if (number < -2147483648 || number > 2147483647)
		{
			free_full_t_arr(*arr_nums);
			error_and_exit();
		}
		else			
			(*arr_nums)->arr[i] = number;
		i++;
	}
	return (1);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_arr(t_arr *arr_nums)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	swapped = 0;
	while (i < arr_nums->size)
	{
		j = 0;
		while (j < (arr_nums->size - i - 1))
		{
			if (arr_nums->arr[j] > arr_nums->arr[j + 1])
			{
				swap(&arr_nums->arr[j], &(arr_nums->arr[j + 1]));
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
		{
			free_full_t_arr(arr_nums);
			exit(0);
		}
		i++;
	}
}

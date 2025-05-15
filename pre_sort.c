/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:08:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/15 19:40:30 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	check_digit(char *s, t_arr *arr_nums)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i = 1;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			free_full_t_arr(arr_nums);
			write (2, "Error\n", 6);;
			exit(1);
		}
		i++;
	}
	return (1);
}
int	fill_array(t_arr **arr_nums, char *nums[])
{
	int	i;

	(*arr_nums)->arr = (int *)malloc((*arr_nums)->size * sizeof(int));
	if (!((*arr_nums)->arr))
		return (0);
	i = 0;
	while ((i < (*arr_nums)->size) && check_digit(nums[i], *arr_nums))
	{
		if (valid_str(nums[i], *arr_nums))
			(*arr_nums)->arr[i] = ft_atoi(nums[i], *arr_nums);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:08:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/14 17:23:10 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	check_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i = 1;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (error_and_return());
		i++;
	}
	return (1);
}
int	fill_array(t_arr **arr_nums, char *nums[])
{
	int	i;
	int	j;

	(*arr_nums)->arr = (int *)malloc((*arr_nums)->size * sizeof(int));
	if (!((*arr_nums)->arr))
		return (0);
	i = 0;
	j = 0;
	while ((i < (*arr_nums)->size) && check_digit(nums[i]))
	{
		if (!valid_str(nums[i]))
			return (error_and_return());
		(*arr_nums)->arr[j] = ft_atoi(nums[i], *arr_nums);
		i++;
		j++;
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

void	sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	swapped = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &(arr[j + 1]));
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
		{
			free(arr);
			exit(0);
		}
		i++;
	}
}

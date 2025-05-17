/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:45:17 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/17 20:41:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

void	error_and_exit(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	free_t_arr_and_return(t_arr *arr_nums)
{
	free(arr_nums);
	return (0);
}

void	free_full_t_arr(t_arr *arr_nums)
{
	int	i;

	i = 0;
	while (arr_nums->numbers[i])
	{
		free(arr_nums->numbers[i]);
		i++;
	}
	free(arr_nums->numbers);
	free(arr_nums->arr);
	free(arr_nums);
}

int	free_full_t_arr_and_return(t_arr *arr_nums)
{
	int	i;

	i = 0;
	while (arr_nums->numbers[i])
	{
		free(arr_nums->numbers[i]);
		i++;
	}
	free(arr_nums->numbers);
	free(arr_nums->arr);
	return (free_t_arr_and_return(arr_nums));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/14 21:49:37 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "parse_input.h"

int	error_and_exit(void)
{
	write (1, "Error\n", 6);
	exit(1);
}

void	cleanup_stacks(t_stack *stack)
{
	t_list_node	*current_node;
	t_list_node	*temp;

	current_node = stack->head;
	while (current_node)
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
	free(stack);
}

int	cleanup_arr(t_arr *arr_nums)
{
	return (free_full_t_arr_and_return(arr_nums));
}

int	check_args(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		error_and_exit();
	else if (argc == 2 && (!ft_strchr(argv[1], ' ')))
		exit (1);
	return (1);
}
// #include <stdio.h>
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_arr	*arr_nums;

	if (!check_args(argc, argv))
		return (1);
	if (!parse_args(&(arr_nums), argc, argv))
		return (1);
	// int i = 0;
	// while (i < arr_nums->size)
	// {
	// 	printf("numbers[%d]: %s\n", i, arr_nums->numbers[i]);
	// 	i++;
	// }
	sort_arr(arr_nums->arr, arr_nums->size);
	if (!arr_nums->arr)
		return (0);
	// i = 0;
	// while (i < arr_nums->size)
	// {
	// 	printf("arr[%d]: %d\n", i, arr_nums->arr[i]);
	// 	i++;
	// }
	a = create_stack();
	if (!a)
		return (1);
	b = create_stack();
	if (!b)
		return (1);
	if (!fill_stack(a, arr_nums))
		return (1);
	// t_list_node *current_node = a->head;
	// i = 0;
	// while (current_node)
	// {
	// 	printf("a[%d] = %d\n", i, current_node->number);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	// printf("size: %d\n", arr_nums->size);
	if (!sort(arr_nums->size, a, b))
		return (1);
	// current_node = a->head;
	// i = 0;
	// while (current_node)
	// {
	// 	printf("a[%d] = %d\n", i, current_node->number);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	cleanup_arr(arr_nums);
	cleanup_stacks(a);
	cleanup_stacks(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:54:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/15 09:45:32 by jkovacev         ###   ########.fr       */
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
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_arr	*arr_nums;

	if (!check_args(argc, argv))
		return (1);
	if (!parse_args(&(arr_nums), argc, argv))
		return (1);
	sort_arr(arr_nums);
	if (!arr_nums->arr)
		return (0);
	a = create_stack();
	if (!a)
		return (1);
	b = create_stack();
	if (!b)
		return (1);
	if (!fill_stack(a, arr_nums))
		return (1);
	if (!sort(arr_nums->size, a, b))
		return (1);
	cleanup_arr(arr_nums);
	cleanup_stacks(a);
	cleanup_stacks(b);
	return (0);
}

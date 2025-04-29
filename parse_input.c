/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:03:25 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/29 09:06:11 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	valid_strlen(char *s)
{
    if (ft_strlen(s) == 0 || (s[0] == '-' && s[1] == '0'))
    {
        write (1, "Error\n", 6);
        exit(1);
    }
    return (1);
}

static int     check_digit(int argc, char *argv[])
{
    int     i;
    int     j;
    
    j = 1;
    while (j < argc)
    {
        i = 0;
        if (valid_strlen(argv[j]))
        {
            if (argv[j][i] == '-')
                i = 1;
            while (argv[j][i])
            {
                if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
                {
                    write (1, "Error\n", 6);
                    return (0);
                }
                i++;
            }
        }
        j++;
    }
	return (1);
}

static int     check_dup(int argc, int *arr)
{
    int     i;
    int     j;

    i = 0;
    while (i < (argc - 1))
    {
        j = i + 1;
        while (j < (argc - 1))
        {
            if (arr[i] == arr[j])
            {
				free(arr);
                write (1, "Error\n", 6);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}
int     parse_args(int **arr, int argc, char *argv[])
{
    if (!check_digit(argc, argv))
        return (0);
    if (!fill_array(arr, argc, argv))
        return (0);
    if (!check_dup(argc, *arr))
        return (0);
    return (1);
}

int    fill_stack(t_stack *stack, int *arr, int n, char *nums[])
{
    int     i;
    int     j;
    int     current_value;
    
    i = n;
    while (i > 0)
    {
        current_value = ft_atoi(nums[i], arr);
        j = 0;
        while(j < n)
        {
            if (current_value == arr[j])
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
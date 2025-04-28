/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:08:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/28 21:56:41 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int     fill_array(int **arr, int n, char *nums[])
{
    int     i;
    int     j;

    *arr = (int *)malloc((n - 1) * sizeof(int));
    if (!(*arr))
        return (0);
    i = 1;
    j = 0;
    while (i < n)
    {
        (*arr)[j] = ft_atoi(nums[i], *arr);
        i++;
        j++;
    }
    return (1);
}

static void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    sort_arr(int *arr, int len)
{
    int     i;
    int     j;
    int     swapped;

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
            exit(0);
        i++;
    }
}

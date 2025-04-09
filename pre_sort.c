/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:08:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 14:06:05 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int     *fill_array(int n, char *nums[])
{
    int     *arr;
    int     i;
    int     j;

    arr = (int *)malloc((n) * sizeof(int));
    if (!arr)
        return (0);
    i = 1;
    j = 0;
    while (i < n)
    {
        arr[j] = ft_atoi(nums[i]);
        i++;
        j++;
    }
    return (arr);
}

static void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

static int    *bubble_sort(int *arr, int len)
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
    return (arr);
}

int     *sort_arr(int n, char *nums[])
{
    int     *arr;

    arr = fill_array(n, nums);
    if (!arr)
        return (0);
    bubble_sort(arr, n - 1);
    return (arr);
}

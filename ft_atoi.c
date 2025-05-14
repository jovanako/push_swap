/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:40:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/14 17:24:11 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while ((n > 0) && (*s1 || *s2))
	{
		if ((*s1 - *s2) != 0)
		{
			write (1, "Error\n", 6);
			return (1);
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}

int	ft_atoi(char *s, t_arr *arr_nums)
{
	int		i;
	int		result;
	int		sign;
	char	*result_str;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]) && (i < ft_strlen(s)))
		result = result * 10 + (s[i++] - '0');
	result *= sign;
	result_str = ft_itoa(result);
	if (ft_strncmp(result_str, s, ft_strlen(s)) != 0)
	{
		free_full_t_arr(arr_nums);
		free(result_str);
		exit(1);
	}
	free(result_str);
	return (result);
}

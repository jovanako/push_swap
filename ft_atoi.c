/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:40:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/12 22:15:33 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_strlen(const char *str)
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
	char	*p1;
	char	*p2;

	p1 = s1;
	p2 = s2;
	if (s2[0] == '-' && s2[1] == '0')
		return (0);
	while ((n > 0) && (*p1 || *p2))
	{
		if ((*p1 - *p2) != 0)
		{
			write (1, "Error\n", 6);
			return (*p1 - *p2);
		}
		n--;
		p1++;
		p2++;
	}
	return (0);
}
int	ft_atoi(char *nptr, int *arr)
{
	int			i;
	int			result;
	int			sign;
	char	*result_str;

	result = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && (i < ft_strlen(nptr)))
		result = result * 10 + (nptr[i++] - '0');
	result *= sign;
	result_str = ft_itoa(result);
	if (ft_strncmp(result_str, nptr, ft_strlen(nptr)) != 0)
	{
		free(arr);
		free(result_str);
		exit(1);
	}
	free(result_str);
	return (result);
}

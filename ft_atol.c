/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:17:03 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/17 21:46:48 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

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

static int	ft_isdigit(char c)
{
	if (!(c >= '0' && c <= '9'))
		error_and_exit();
	return (1);
}

static int	remove_special_characters(char *n)
{
	int	i;

	i = 0;
	while (n[i] == ' ' || (n[i] >= 9 && n[i] <= 13))
	{
		i++;
	}
	return (i);
}

long int	ft_atol(char *nptr)
{
	int			i;
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	i = remove_special_characters(nptr);
	if (nptr[i] == '+')
	{
		i++;
	}
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((i < ft_strlen(nptr)) && ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:40:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/31 21:45:17 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi(char *nptr)
{
	int 	i;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	// if (nptr[i] == '+')
	// {
	// 	i++;
	// }
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && (i < ft_strlen(nptr)))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}
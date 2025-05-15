/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:46:34 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/15 21:08:32 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	is_int(char *s)
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
		free(result_str);
		exit(1);
	}
	free(result_str);
}

int	str_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i = 1;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check_one_arg(char *s)
{
	if (ft_strlen(s) == 0 || (s[0] == '-' && s[1] == '0'))
		error_and_exit();
	else if (!str_isdigit(s))
		error_and_exit();
	else if (ft_strlen(s) > 1 && s[0] == '0')
		error_and_exit();
	else
		is_int(s);
	exit(0);
}
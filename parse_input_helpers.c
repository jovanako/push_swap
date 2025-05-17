/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:25:48 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/17 21:04:45 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

char	*ft_strchr(char *s, char c)
{
	while (*s || *s == c)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (0);
}

static int	calculate_substring_size(int start_index,
		int src_length, int max_len)
{
	if (start_index < src_length)
	{
		if (max_len <= (src_length - start_index))
		{
			return (max_len);
		}
		return (src_length - start_index);
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;
	int		j;
	int		s_len;
	int		substring_size;

	s_len = ft_strlen(s);
	substring_size = calculate_substring_size(start, s_len, len);
	substr = (char *) malloc (substring_size * sizeof(char) + 1);
	if (!substr)
		return (0);
	i = 0;
	j = start;
	while ((j < s_len) && (j < (start + len)))
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	substr[i] = '\0';
	return (substr);
}

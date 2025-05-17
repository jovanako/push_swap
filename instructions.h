/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:00:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/05/16 12:01:59 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "parse_input.h"

int	swap_first_two(t_stack *stack);
int	ss(t_stack *a, t_stack *b);
int	push_to_other(t_stack *dest, t_stack *src);
int	rotate(t_stack *stack);
int	rr(t_stack *a, t_stack *b);
int	rev_rotate(t_stack *stack);
int	rrr(t_stack *a, t_stack *b);

#endif

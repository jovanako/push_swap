/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:26 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/08 14:22:17 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list_node
{
    int      	        number;
    struct s_list_node	*next;
}   t_list_node;

t_list_node	*new_node(int number);
void		add_front(t_list_node **head, t_list_node *new_node);
void		add_back(t_list_node **tail, t_list_node *new_node);
int    	    remove_front(t_list_node **head);
int		    remove_back(t_list_node **tail);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:09:19 by jkovacev          #+#    #+#             */
/*   Updated: 2025/04/09 20:28:59 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_node	*new_node(int number)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_front(t_list_node **head, t_list_node *new_node)
{
	new_node->next = *head;
	*head = new_node;
}

void	add_back(t_list_node **tail, t_list_node *new_node)
{
    if (*tail)
	    (*tail)->next = new_node;
	*tail = new_node;
}

int		remove_front(t_list_node **head)
{
    t_list_node *temp;
	int			value;

	temp = (t_list_node *)malloc(sizeof(t_list_node));
    if (*head)
    {
		value = (*head)->number;
        temp = *head;
        *head = (*head)->next;
        free(temp);
		return (value);
    }
	exit(1);
}

int		remove_back(t_list_node **tail)
{
	int			value;

    if (*tail)
    {
		value = (*tail)->number;
		free(*tail);
		return (value);
	}
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 23:02:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

void	insert_node(t_node **head, t_node *new)
{
	while (*head)
	{
		if (new < *head)
		{
			new->next = *head;
			*head = new;
			return ;
		}
		head = &(*head)->next;
	}
	*head = new;
}

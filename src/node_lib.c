/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:28:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 16:07:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_internal.h"

t_node	**find_node_firstfit(t_node **node, size_t size)
{
	/* if (*node) */
	/* { */
	/* 	ft_putstr("startf@"); */
	/* 	print_node(BG_CYAN, *node); */
	/* } */
	while (*node && (size_t)(*node)->size < size + HEADER_SIZE)
	{
		node = &(*node)->next;
		/* ft_putstr("firstf@"); */
		/* print_node(FG_GREEN, *node); */
	}
	return (node);
}

t_node	*split_node(t_node **node, t_node **alloc, t_node **zone, size_t size)
{
	t_node	*new_alloc;
	int		free_size;

	free_size = (*node)->size;
	new_alloc = *node;
	/* ft_putstr("node->data @ ["); */
	/* ft_putaddr((*node)->data); */
	/* ft_putendl("]"); */
	*node = (t_node*)((*node)->data + size);
	/* ft_putstr("node @ ["); */
	/* ft_putaddr(*node); */
	/* ft_putendl("]"); */
	(*node)->size = free_size - (size + HEADER_SIZE);
	if ((*node)->size == 0)
		remove_node(zone, *node);
	new_alloc->size = size;
	insert_node(alloc, new_alloc);
	return (new_alloc);
}


int		remove_node(t_node **head, t_node *node)
{
	while (*head)
	{
		ft_putstr("looking for node -> [");
		ft_putnbr_hex((long)node);
		ft_putstr(",");
		ft_putnbr_hex((long)*head);
		ft_putendl("]");
		if (*head == node)
		{
			*head = (*head)->next;
			return (0);
		}
		head = &(*head)->next;
	}
	return (1);
}

void	insert_node(t_node **head, t_node *new)
{
	while (*head)
	{
		if (new < *head)
			break ;
		head = &(*head)->next;
	}
	new->next = *head;
	*head = new;
}

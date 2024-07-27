/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:49:31 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/26 16:42:18 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int data)
{
	t_node	*l;

	l = (t_node *)malloc(sizeof(t_node));
	if (!l)
		return (0);
	l->data = data;
	l->next = NULL;
	l->prev = NULL;
	return (l);
}

void	clear_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	
	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:28:06 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/28 17:29:09 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_program *main, char **split_args)
{
	clear_nodes(main->stack_a);
	clear_nodes(main->stack_b);
	if (main->array)
		free(main->array);
	if (split_args)
		free_split(split_args);
	ft_error(1);
}

void	push_back(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = ft_lstnew(data);
	new_node->prev = stack->bottom->prev;
	new_node->next = stack->bottom;
	stack->bottom->prev->next = new_node;
	stack->bottom->prev = new_node;
	stack->size++;
}

void	initialize_stack(t_program *main)
{
	t_node	*current;
	int		i;

	current = main->stack_a->top->next;
	i = 0;
	while (current != main->stack_a->bottom)
	{
		current->data = main->array[i];
		current = current->next;
		i++;
	}
}

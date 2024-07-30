/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:16:40 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 13:53:48 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->top->next == stack->bottom)
		ft_error(1);
	node = stack->top->next;
	stack->top->next = node->next;
	node->next->prev = stack->top;
	stack->size--;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
	node->next = stack->top->next;
	node->prev = stack->top;
	stack->top->next->prev = node;
	stack->top->next = node;
	stack->size++;
}

void	pa(t_program *main)
{
	t_node	*node;

	node = pop(main->stack_b);
	if (node != NULL)
		push(main->stack_a, node);
	ft_printf("pa\n");
}

void	pb(t_program *main)
{
	t_node	*node;

	node = pop(main->stack_a);
	if (node != NULL)
		push(main->stack_b, node);
	ft_printf("pb\n");
}

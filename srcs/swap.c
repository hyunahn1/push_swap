/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:21:44 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 12:59:09 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->top == NULL || stack->top->next == NULL)
		ft_error(1);
	first = stack->top->next;
	second = stack->top->next->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = stack->top;
	second->next = first;
	first->prev = second;
	stack->top->next = second;
	if (first->next == stack->bottom)
		stack->bottom->prev = first;
}

void	sa(t_program *main)
{
	if (main->stack_a->size < 2)
	{
		clear_nodes(main->stack_a);
		clear_nodes(main->stack_b);
		ft_error(1);
	}
	swap(main->stack_a);
	ft_printf("sa\n");
}

void	sb(t_program *main)
{
	if (main->stack_a->size < 2)
	{
		clear_nodes(main->stack_a);
		clear_nodes(main->stack_b);
		ft_error(1);
	}
	swap(main->stack_b);
	ft_printf("sb\n");
}

void	ss(t_program *main)
{
	if (main->stack_a->size < 2)
	{
		clear_nodes(main->stack_a);
		clear_nodes(main->stack_b);
		ft_error(1);
	}
	swap(main->stack_a);
	swap(main->stack_b);
	ft_printf("ss\n");
}

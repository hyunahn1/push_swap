/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:17:50 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 14:33:01 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->top->next == stack->bottom)
		ft_error(1);
	first = stack->top->next;
	stack->top->next = first->next;
	first->next->prev = stack->top;
	last = stack->bottom->prev;
	last->next = first;
	first->prev = last;
	first->next = stack->bottom;
	stack->bottom->prev = first;
}

void	ra(t_program *main)
{
	rotate(main->stack_a);
	ft_printf("ra\n");
}

void	rb(t_program *main)
{
	rotate(main->stack_b);
	ft_printf("rb\n");
}

void	rr(t_program *main)
{
	rotate(main->stack_a);
	rotate(main->stack_b);
	ft_printf("rr\n");
}

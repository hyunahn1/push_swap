/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:38:27 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 14:50:40 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (stack->top->next == stack->bottom)
		ft_error(1);
	last = stack->bottom->prev;
	last->prev->next = stack->bottom;
	stack->bottom->prev = last->prev;
	last->next = stack->top->next;
	last->prev = stack->top;
	stack->top->next->prev = last;
	stack->top->next = last;
}

void	rra(t_program *main)
{
	reverse_rotate(main->stack_a);
	ft_printf("rra\n");
}

void	rrb(t_program *main)
{
	reverse_rotate(main->stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_program *main)
{
	reverse_rotate(main->stack_a);
	reverse_rotate(main->stack_b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:56:55 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 19:56:56 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top->next;
	while (current->next != stack->bottom)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min_idx(t_stack *stack)
{
	int		min_idx;
	int		i;
	t_node	*current;
	int		min_value;

	min_idx = 0;
	i = 0;
	current = stack->top->next;
	min_value = current->data;
	while (current != stack->bottom)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			min_idx = i;
		}
		current = current->next;
		i++;
	}
	return (min_idx);
}

void	ft_sort_small(t_program *main)
{
	int	size;
	int	i;
	int	min_idx;

	if (is_sorted(main->stack_a))
		return ;
	size = main->stack_a->size;
	i = 0;
	min_idx = 0;
	while (main->stack_a->size > 3)
	{
		min_idx = find_min_idx(main->stack_a);
		i = 0;
		if (min_idx <= main->stack_a->size / 2)
			while (i++ < min_idx)
				ra(main);
		else
			while (i++ < main->stack_a->size - min_idx)
				rra(main);
		pb(main);
	}
	ft_sort_three(main);
	while (main->stack_b->size > 0)
		pa(main);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:00:26 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 19:55:10 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_program *main)
{
	if (main->stack_a->top->next->data > main->stack_a->top->next->next->data)
		sa(main);
}

void	ft_sort_three(t_program *main)
{
	int	a;
	int	b;
	int	c;

	a = main->stack_a->top->next->data;
	b = main->stack_a->top->next->next->data;
	c = main->stack_a->bottom->prev->data;
	if (a > b && b > c)
	{
		sa(main);
		rra(main);
	}
	else if (a > c && c > b)
		ra(main);
	else if (b > a && a > c)
		rra(main);
	else if (b > c && c > a)
	{
		sa(main);
		ra(main);
	}
	else if (c > a && a > b)
	{
		sa(main);
	}
}

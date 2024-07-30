/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:17:42 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 19:09:26 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_program *main, int size)
{
	if (is_sorted(main->stack_a))
		return ;
	if (size == 1)
		return ;
	else if (size == 2)
		ft_sort_two(main);
	else if (size == 3)
		ft_sort_three(main);
	else if (size <= 6)
		ft_sort_small(main);
	else
		ft_sort_big(main);
}

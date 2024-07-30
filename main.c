/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:24:56 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 19:10:37 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_program *main)
{
	main->stack_a = (t_stack *)malloc(sizeof(t_stack));
	main->stack_b = (t_stack *)malloc(sizeof(t_stack));
	main->stack_a->top = ft_lstnew(0);
	main->stack_a->bottom = ft_lstnew(0);
	main->stack_a->top->next = main->stack_a->bottom;
	main->stack_a->bottom->prev = main->stack_a->top;
	main->stack_b->top = ft_lstnew(0);
	main->stack_b->bottom = ft_lstnew(0);
	main->stack_b->top->next = main->stack_b->bottom;
	main->stack_b->bottom->prev = main->stack_b->top;
	main->array_size = 0;
	main->stack_a->size = 0;
	main->stack_b->size = 0;
}

int	main(int argc, char **argv)
{
	t_program	main;

	main.stack_a = NULL;
	main.stack_b = NULL;
	if (argc < 2)
		ft_error(0);
	init_stack(&main);
	parse_argv(&main, argc, argv);
	push_swap(&main, main.stack_a->size);
	free(main.array);
	clear_nodes(main.stack_a);
	clear_nodes(main.stack_b);
	return (0);
}

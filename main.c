/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:24:56 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/13 17:39:21 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_program	main;

	main.stack_a = NULL;
	main.stack_b = NULL;
	if (argc < 2)
		ft_error(1);
	main.array = parsing_stack(argc, argv, main);
	ft_stack_len(main.stack_a);
	push_swap(main, main->stack_a.size);
	clear_nodes(main.stack_a);
	clear_nodes(main.stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:24:56 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 11:13:44 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack) {
    t_node *current = stack->top->next; // Skip the dummy node
    printf("Stack A: ");
    while (current != stack->bottom) { // Until the dummy bottom node
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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
	//디버깅 하는 중
	printf("Before swap:\n");
	print_stack(main.stack_a);
    	printf("After sa (swap a):\n");
    	sa(&main);
    	print_stack(main.stack_a);
    	pb(&main);
    	printf("After pa :\n");
    	print_stack(main.stack_a);
    	print_stack(main.stack_b);
    	ra(&main);
    	print_stack(main.stack_a);
    	print_stack(main.stack_b);
    	rra(&main);
    	print_stack(main.stack_a);
    	print_stack(main.stack_b);
    	//디버깅 끝
	//push_swap(main, main->stack_a.size);
	clear_nodes(main.stack_a);
	clear_nodes(main.stack_b);
	return (0);
}

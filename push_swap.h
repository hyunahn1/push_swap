/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:38:41 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/26 15:12:19 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int	data;
}		t_node;

typedef struct s_stack
{
	int	size;
	t_node	*top;
	t_node	*bottom;
}		t_stack;

typedef struct s_program
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	*array;
	int	array_size;
}		t_program;

int	ft_atoi(const char *nptr);
int	ft_error(int num);
t_node	*ft_lstnew(int data);
void	clear_nodes(t_stack *stack);
void	ft_putendl_fd(char *s, int fd);

void print_stack(t_stack *stack);
void	init_stack(t_program *main);

void	push_back(t_stack *stack, int data);
void	parse_argv(t_program *main, int argc, char **argv);
void	replace_with_index(t_program main);

void	swap(t_stack *stack);
void sa(t_program *main);
void sb(t_program *main);
void ss(t_program *main);

t_node *pop(t_stack *stack);
void push(t_stack *stack, t_node *node);
void pa(t_program *main);
void pb(t_program *main);

void    rotate(t_stack *stack);
void    ra(t_program *main);
void    rb(t_program *main);
void    rr(t_program *main);

void    reverse_rotate(t_stack *stack);
void    rra(t_program *main);
void    rrb(t_program *main);
void    rrr(t_program *main);

#endif

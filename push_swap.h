/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:38:41 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/13 17:06:00 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "printf.h"

typedef struct s_node
{
	s_stack *prev;
	s_stack	*next;
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
}		t_program;

#endif

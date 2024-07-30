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
# define PUSH_SWAP_H

# include "../printf/printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	struct s_node		*prev;
	struct s_node		*next;
	int					data;
}		t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}		t_stack;

typedef struct s_program
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*array;
	int			array_size;
	int			*pivots;
}		t_program;

int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_error(int num);
void			free_split(char **split);
t_node			*ft_lstnew(int data);
void			clear_nodes(t_stack *stack);
void			ft_putendl_fd(char *s, int fd);
t_stack			*ft_lstlast(t_stack *lst);

void			print_stack_a(t_stack *stack);
void			print_stack_b(t_stack *stack);
void			init_stack(t_program *main);

void			push_back(t_stack *stack, int data);
void			parse_argv(t_program *main, int argc, char **argv);
void			replace_with_index(t_program main);

void			swap(t_stack *stack);
void			sa(t_program *main);
void			sb(t_program *main);
void			ss(t_program *main);

t_node			*pop(t_stack *stack);
void			push(t_stack *stack, t_node *node);
void			pa(t_program *main);
void			pb(t_program *main);

void			rotate(t_stack *stack);
void			ra(t_program *main);
void			rb(t_program *main);
void			rr(t_program *main);

void			reverse_rotate(t_stack *stack);
void			rra(t_program *main);
void			rrb(t_program *main);
void			rrr(t_program *main);

void			push_swap(t_program *main, int size);
void			ft_sort_two(t_program *main);
void			ft_sort_three(t_program *main);
void			ft_sort_small(t_program *main);
int				find_min_idx(t_stack *stack);
void			ft_sort_big(t_program *main);

char			**ft_split(char const *s, char c);
static char		**ft_free_all(char **str);
static size_t	ft_result_word(const char *s, char c);
static char		*plus_str(char const *s, char c);
static int		all_str_put(char const *s, char c, char **str, size_t i);

int				is_integer(const char *str);
int				has_duplicates(int *array, int size);
void			quicksort(int *arr, int low, int high);
void			handle_error(t_program *main, char **split_args);
void			initialize_stack(t_program *main);
int				is_sorted(t_stack *stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:32:04 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 11:08:28 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(const char *str)
{
	int	i;
	int	sign;
	long	num;

	i = 0;
	sign = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign && -num < -2147483648) || (!sign && num > 2147483647))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	push_back(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = ft_lstnew(data);
	new_node->prev = stack->bottom->prev;
	new_node->next = stack->bottom;
	stack->bottom->prev->next = new_node;
	stack->bottom->prev = new_node;
	stack->size++;
}

void	quicksort_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			quicksort_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	quicksort_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;
	
	pi = 0;
	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void	parse_argv(t_program *main, int argc, char **argv)
{
	int	i;
	int	num;
	int	*sorted_array;
	int	j;
	t_node	*current;

	i = 0;
	main->array_size = argc - 1;
	main->array = (int *)malloc(sizeof(int) * main->array_size);
	sorted_array = (int *)malloc(sizeof(int) * main->array_size);
	if (!main->array || !sorted_array)
		ft_error(1);
	while (i < main->array_size)
	{
		if (!is_integer(argv[i + 1]))
		{
			clear_nodes(main->stack_a);
			clear_nodes(main->stack_b);
			free(sorted_array);
			free(main->array);
			ft_error(1);
		}
		num = ft_atoi(argv[i + 1]);
		main->array[i] = num;
		sorted_array[i] = num;
		push_back(main->stack_a, num);
		i++;
	}
	if (has_duplicates(main->array, main->array_size))
	{
		clear_nodes(main->stack_a);
		clear_nodes(main->stack_b);
		free(sorted_array);
		free(main->array);
		ft_error(1);
	}
	quicksort(sorted_array, 0, main->array_size - 1);
	i = 0;
	while (i < main->array_size)
	{
		j = 0;
		while (j < main->array_size)
		{
			if (main->array[i] == sorted_array[j])
			{
				main->array[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	current = main->stack_a->top->next;
	i = 0;
	while (current != main->stack_a->bottom)
	{
		current->data = main->array[i];
		current = current->next;
		i++;
	}
	free(sorted_array);
	free(main->array);
}

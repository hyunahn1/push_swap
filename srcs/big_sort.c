/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:57:07 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/28 14:25:26 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	*calculate_pivots(int *array, int size)
{
	int	*pivots;
	int	*temp_array;
	int	i;

	i = 0;
	pivots = (int *)malloc(2 * sizeof(int));
	temp_array = (int *)malloc(size * sizeof(int));
	if (!pivots || !temp_array)
		ft_error(1);
	while (i++ < size)
		temp_array[i] = array[i];
	quicksort(temp_array, 0, size - 1);
	pivots[0] = temp_array[size / 3];
	pivots[1] = temp_array[2 * size / 3];
	free(temp_array);
	return (pivots);
}


void	partition_by_pivots(t_program *main, int *pivots)
{
	int	original_size;
	int	i;
	int	j;

	original_size = main->stack_a->size;
	i = 0;
	while (i < original_size)
	{
		if (main->stack_a->top->next->data < pivots[0])
		{
			pb(main);
			if (main->stack_b->size > 1)
				rb(main);
		}
		else if (main->stack_a->top->next->data < pivots[1])
		{
			pb(main);
		}
		else
		{
			ra(main);
		}
		i++;
	}
}

void	ft_sort_big(t_program *main)
{
	int	size;
	int	*pivots;
	int	less_pivot_size;
	int	between_pivot_size;

	size = main->stack_a->size;
	pivots = calculate_pivots(main->array, size);
	partition_by_pivots(main, pivots);
	free(pivots);
}
*/

#include "push_swap.h"

int	*calculate_pivots(int *array, int size)
{
	int	*pivots;
	int	min_val;
	int	max_val;
	int	larger_pivot;
	int	smaller_pivot;
	int	i;

	i = 1;
	pivots = (int *)malloc(2 * sizeof(int));
	if (!pivots)
		ft_error(1);

	min_val = array[0];
	max_val = array[0];

	while (i++ < size)
	{
		if (array[i] < min_val)
			min_val = array[i];
		if (array[i] > max_val)
			max_val = array[i];
	}

	larger_pivot = (max_val + min_val) / 2;
	smaller_pivot = (larger_pivot + min_val) / 2;

	pivots[0] = smaller_pivot;
	pivots[1] = larger_pivot;

	return pivots;
}

void	partition_by_pivots(t_program *main, int *pivots)
{
	int	original_size;
	int	i;

	original_size = main->stack_a->size;
	for (i = 0; i < original_size; i++)
	{
		if (main->stack_a->top->next->data < pivots[0])
			pb(main);
		else if (main->stack_a->top->next->data < pivots[1])
			pb(main);
		else
			ra(main);
	}
}

void	push_back_to_a(t_program *main)
{
	while (main->stack_b->size > 0)
	{
		pa(main);
	}
}

void	recalculate_pivots_and_partition(t_program *main)
{
	int	*array;
	int	size;
	int	*pivots;
	t_node	*current;
	int	i;

	i = 0;
	size = main->stack_a->size;
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		ft_error(1);

	current = main->stack_a->top->next;
	while (i++ < size)
	{
		array[i] = current->data;
		current = current->next;
	}

	pivots = calculate_pivots(array, size);
	partition_by_pivots(main, pivots);
	free(array);
	free(pivots);
}

void	ft_sort_big(t_program *main)
{
	int	size;
	int	*pivots;

	size = main->stack_a->size;
	pivots = calculate_pivots(main->array, size);
	partition_by_pivots(main, pivots);
	free(pivots);
	while (main->stack_a->size > 3)
			recalculate_pivots_and_partition(main);
	if (main->stack_a->size == 3)
		ft_sort_three(main);
}


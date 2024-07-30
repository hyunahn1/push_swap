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

/*
void	parse_argv(t_program *main, int argc, char **argv)
{
	int	i;
	int	num;
	int	*sorted_array;
	int	j;
	t_node	*current;
	char	**split_args;
	int	split_count;
	int	k;

	i = 1;
	split_count = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		k = 0;
		while (split_args[k] != NULL)
		{
			split_count++;
			k++;
		}
		free_split(split_args);
		i++;
	}
	main->array_size = split_count;
	main->array = (int *)malloc(sizeof(int) * main->array_size);
	sorted_array = (int *)malloc(sizeof(int) * main->array_size);
	if (!main->array || !sorted_array)
		ft_error(1);
	i = 1;
	split_count = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		k = 0;
		while (split_args[k] != NULL)
		{
			if (!is_integer(split_args[k]))
			{
				clear_nodes(main->stack_a);
				clear_nodes(main->stack_b);
				free(sorted_array);
				free(main->array);
				free_split(split_args);
				ft_error(1);
			}
			num = ft_atoi(split_args[k]);
			main->array[split_count] = num;
			sorted_array[split_count] = num;
			push_back(main->stack_a, num);
			split_count++;
			k++;
		}
		free_split(split_args);
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
}
*/

void	process_input(t_program *main, int argc, char **argv)
{
	int		i;
	int		k;
	int		split_count;
	char	**split_args;

	i = 1;
	split_count = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		k = 0;
		while (split_args[k] != NULL)
		{
			split_count++;
			k++;
		}
		free_split(split_args);
		i++;
	}
	main->array_size = split_count;
	main->array = (int *)malloc(sizeof(int) * main->array_size);
	if (!main->array)
		ft_error(1);
}

void	fill_arrays(t_program *main, int argc, char **argv)
{
	int		i;
	int		k;
	int		split_count;
	int		num;
	char	**split_args;

	i = 1;
	split_count = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		k = 0;
		while (split_args[k] != NULL)
		{
			if (!is_integer(split_args[k]))
				handle_error(main, split_args);
			num = ft_atoi(split_args[k]);
			main->array[split_count] = num;
			push_back(main->stack_a, num);
			split_count++;
			k++;
		}
		free_split(split_args);
		i++;
	}
}

void	replace_with_indices(t_program *main, int *sorted_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < main->array_size)
	{
		j = 0;
		while (j < main->array_size)
		{
			if (main->array[i] == sorted_array[j])
			{
				main->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	check_duplicates_and_sort(t_program *main)
{
	int		i;
	int		*sorted_array;

	sorted_array = (int *)malloc(sizeof(int) * main->array_size);
	if (!sorted_array)
		handle_error(main, NULL);
	i = 0;
	while (i < main->array_size)
	{
		sorted_array[i] = main->array[i];
		i++;
	}
	if (has_duplicates(main->array, main->array_size))
		handle_error(main, NULL);
	quicksort(sorted_array, 0, main->array_size - 1);
	replace_with_indices(main, sorted_array);
	free(sorted_array);
}

void	parse_argv(t_program *main, int argc, char **argv)
{
	process_input(main, argc, argv);
	fill_arrays(main, argc, argv);
	check_duplicates_and_sort(main);
	initialize_stack(main);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:58:32 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/28 09:59:31 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_integer(const char *str)
{
	int		i;
	int		sign;
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
		if ((sign && (-num < -2147483648)) || (!sign && num > 2147483647))
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

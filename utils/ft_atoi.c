/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:40:48 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:40:51 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t	except;
	size_t	denary;
	int		i;

	i = 0;
	except = 1;
	denary = 0;
	while (nptr[i] == 32 || (nptr[i] >= 8 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			except *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		denary *= 10;
		denary += nptr[i] - 48;
		i++;
	}
	return (denary * except);
}

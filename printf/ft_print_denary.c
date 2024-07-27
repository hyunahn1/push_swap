/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_denary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:43:12 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:43:15 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long	check_len(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	itoa_play(long n)
{
	if (n > 9)
		itoa_play(n / 10);
	ft_print_char(n % 10 + '0');
}

int	ft_itoa(int n)
{
	long	i;
	int		size;

	i = n;
	size = 0;
	if (i < 0)
	{
		ft_print_char('-');
		i *= -1;
		size += 1;
	}
	size += check_len(i);
	itoa_play(i);
	return (size);
}

int	ft_unsigned_itoa(int n)
{
	unsigned int	i;
	char			*base;
	int				size;

	i = (unsigned int)n;
	size = 0;
	size += check_len(i);
	base = "0123456789";
	itoa_play(i);
	return (size);
}

int	ft_print_denary(int nbr, char form)
{
	int	len;

	len = 0;
	if (form == 'd' || form == 'i')
		len += ft_itoa(nbr);
	else
		len += ft_unsigned_itoa(nbr);
	return (len);
}

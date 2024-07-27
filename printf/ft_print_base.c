/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:42:43 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:42:45 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_len(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	recursive(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
		recursive(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

int	select_p(unsigned long long p, char *base)
{
	size_t	len;

	base = "0123456789abcdef";
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ft_putstr("0x");
		recursive(p, base);
		len = check_len(p);
		len += 2;
	}
	return (len);
}

int	ft_print_base(unsigned int nbr, char form)
{
	size_t	len;
	char	*base;

	len = 0;
	if (form == 'x')
	{
		base = "0123456789abcdef";
		recursive(nbr, base);
		len += check_len(nbr);
	}
	else if (form == 'X')
	{
		base = "0123456789ABCDEF";
		recursive(nbr, base);
		len += check_len(nbr);
	}
	return (len);
}

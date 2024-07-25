/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:21:25 by hyunahn           #+#    #+#             */
/*   Updated: 2024/04/14 16:46:07 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			len += ft_plustype(form[i + 1], &args);
			i++;
		}
		else
			len += ft_print_char(form[i]);
		i++;
	}
	va_end(args);
	return (len);
}

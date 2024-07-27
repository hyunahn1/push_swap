/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:43:24 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:43:25 by hyunahn          ###   ########.fr       */
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

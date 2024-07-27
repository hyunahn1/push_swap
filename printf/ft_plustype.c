/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plustype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <hyunahn@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:42:29 by hyunahn           #+#    #+#             */
/*   Updated: 2024/07/27 17:42:31 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_plustype(char form, va_list *args)
{
	if (form == 'c')
		return (ft_print_char((char)va_arg(*args, int)));
	else if (form == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (form == '%')
		return (ft_print_char('%'));
	else if (form == 'x' || form == 'X' || form == 'p')
	{
		if (form == 'p')
			return (select_p(va_arg(*args, unsigned long long), &form));
		else
			return (ft_print_base(va_arg(*args, unsigned int), form));
	}
	else if (form == 'd' || form == 'i' || form == 'u')
		return (ft_print_denary(va_arg(*args, int), form));
	return (0);
}

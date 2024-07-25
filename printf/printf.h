/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:56:29 by hyunahn           #+#    #+#             */
/*   Updated: 2024/04/14 18:01:34 by hyunahn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *form, ...);
int		ft_plustype(char form, va_list *args);
int		ft_print_base(unsigned int nbr, char form);
int		ft_print_char(char c);
int		ft_print_denary(int nbr, char form);
int		ft_print_str(char *s);
int		ft_putstr(char *s);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		select_p(unsigned long long p, char *base);

#endif

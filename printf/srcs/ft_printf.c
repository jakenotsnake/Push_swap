/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:14:52 by jtanner           #+#    #+#             */
/*   Updated: 2022/07/09 15:40:45 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "../includes/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list	*args, const char format, int *i)
{
	if (format == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(*args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_printnum(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_printf_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_printchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		printlen;

	i = 0;
	printlen = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printlen += ft_formats(&args, str[i + 1], &i);
			i++;
		}
		else
			printlen += ft_printchar(str[i]);
			i++;
	}
	va_end(args);
	return (printlen);
}

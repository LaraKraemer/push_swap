/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:43:40 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 18:34:20 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	int printf(const char *, ...)
	Takes a undefined number of variables and prints them as standard output
*/
#include "ft_printf.h"

static int	ft_print_format(char identifier, va_list *ap)
{
	int	count;

	count = 0;
	if (identifier == 'c')
		count += ft_print_char(va_arg(*ap, int));
	else if (identifier == 's')
		count += ft_print_str(va_arg(*ap, char *));
	else if (identifier == 'd' || identifier == 'i')
		count += ft_print_digit((long)va_arg(*ap, int));
	else if (identifier == 'p')
		count += ft_print_ptr(va_arg(*ap, void *));
	else if (identifier == 'u')
		count += ft_print_unsigned_digit((long)va_arg(*ap, unsigned int));
	else if (identifier == 'x')
		count += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 0);
	else if (identifier == 'X')
		count += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 1);
	else if (identifier == '%')
		count += ft_print_char('%');
	else
		count += write(1, &identifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_print_format(*format, &ap);
		}
		else
			count += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

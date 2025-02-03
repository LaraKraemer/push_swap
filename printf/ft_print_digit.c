/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:16:25 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 17:30:59 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n)
{
	int	count;

	count = 0;
	if (n == LONG_MIN)
	{
		count += ft_print_char('-');
		n = -(n / 10);
		count += ft_print_digit(n);
		count += ft_print_char('8');
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_digit(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

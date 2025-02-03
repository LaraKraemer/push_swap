/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:31:35 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 18:34:41 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_digit(uintptr_t n)
{
	size_t	digit_count;

	digit_count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digit_count++;
		n = n / 16;
	}
	return (digit_count);
}

static void	write_hex(uintptr_t n, int is_uppercase)
{
	static char	upper_digit[] = "0123456789ABCDEF";
	static char	lower_digit[] = "0123456789abcdef";

	if (n >= 16)
		write_hex(n / 16, is_uppercase);
	if (is_uppercase)
		write(1, &upper_digit[n % 16], 1);
	else 
		write(1, &lower_digit[n % 16], 1);
}

int	ft_print_hex(uintptr_t n, int is_uppercase)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	write_hex(n, is_uppercase);
	count = hex_digit(n);
	return (count);
}

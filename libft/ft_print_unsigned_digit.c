/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:14:04 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/10 14:53:02 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_digit(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_char('0');
		return (count);
	}
	if (n >= 10)
		count += ft_print_unsigned_digit(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

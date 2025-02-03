/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:21 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 18:34:30 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	count += ft_print_str("0x");
	addr = (uintptr_t)ptr;
	count += ft_print_hex(addr, 0);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:14:56 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 16:31:16 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_print_char((int)str[i]);
		i++;
		count++;
	}
	return (count);
}

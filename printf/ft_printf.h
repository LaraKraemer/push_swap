/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:58:47 by lkramer           #+#    #+#             */
/*   Updated: 2024/12/04 18:33:53 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h> 
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_digit(long n);
int	ft_print_unsigned_digit(unsigned long n);
int	ft_print_hex(uintptr_t n, int is_uppercase);
int	ft_print_ptr(void *ptr);

#endif

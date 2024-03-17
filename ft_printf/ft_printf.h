/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:46:06 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/29 20:41:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
size_t	get_num_len(long num);
int		get_type(va_list ap, const char *str);
void	init_print_type(int (*type [])(va_list));
int		print_address(va_list ap);
int		print_character(va_list ap);
int		print_demical(va_list ap);
int		print_lower_hexademical(va_list ap);
int		print_percent(va_list ap);
int		print_string(va_list ap);
int		print_unsigned_demical(va_list ap);
int		print_upper_hexademical(va_list ap);
int		ft_nbrlen(size_t n, int radix);
void	num_to_string(char *buf, uintptr_t n, int radix, char *base);
#endif
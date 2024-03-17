/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:11:13 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/08 13:39:06 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_type(int (*type [])(va_list), va_list ap, int types)
{
	if (type[(unsigned char)types])
		return (type[(unsigned char)types](ap));
	else
		return (-1);
}

int	get_type(va_list ap, const char *str)
{
	int	(*type[256])(va_list);
	int	print_len;
	int	tmp;

	init_print_type(type);
	print_len = 0;
	tmp = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			tmp = select_type(type, ap, *str);
			if (tmp == -1)
				return (-1);
			print_len += tmp;
		}
		else
		{
			write(1, str, 1);
			print_len += 1;
		}
		str++;
	}
	return (print_len);
}

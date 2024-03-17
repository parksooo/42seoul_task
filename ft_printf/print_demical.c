/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_demical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:43:53 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/29 20:29:04 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_demical(va_list ap)
{
	long		num;
	char		buf[11];
	int			len;

	num = va_arg(ap, int);
	if (num < 0)
	{
		buf[0] = '-';
		num *= -1;
		num_to_string(buf + 1, num, 10, "0123456789");
		len = ft_nbrlen(num, 10) + 1;
	}
	else
	{
		num_to_string(buf, num, 10, "0123456789");
		len = ft_nbrlen(num, 10);
	}
	return (write(1, buf, len));
}

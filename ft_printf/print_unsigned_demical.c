/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_demical.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:23:03 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/28 17:24:10 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_demical(va_list ap)
{
	unsigned int	num;
	int				len;
	char			buf[10];

	num = va_arg(ap, unsigned int);
	num_to_string(buf, num, 10, "0123456789");
	len = ft_nbrlen(num, 10);
	return (write(1, buf, len));
}

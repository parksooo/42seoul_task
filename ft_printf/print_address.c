/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:36:17 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/07 16:31:54 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address(va_list ap)
{
	unsigned long long	addr;
	char				buf[18];
	int					len;

	buf[0] = '0';
	buf[1] = 'x';
	addr = va_arg(ap, unsigned long long);
	num_to_string(buf + 2, addr, 16, "0123456789abcdef");
	len = ft_nbrlen(addr, 16);
	return (write(1, buf, len + 2));
}

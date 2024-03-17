/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lower_hexademical.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:07 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/29 20:37:32 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lower_hexademical(va_list ap)
{
	char			buf[16];
	unsigned int	num;
	size_t			len;

	num = va_arg(ap, unsigned int);
	num_to_string(buf, num, 16, "0123456789abcdef");
	len = ft_nbrlen(num, 16);
	return (write(1, buf, len));
}

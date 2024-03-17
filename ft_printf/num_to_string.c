/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:04:11 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/29 12:42:48 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_to_string(char *buf, uintptr_t n, int radix, char *base)
{
	int	len;

	len = ft_nbrlen(n, radix);
	if (n == 0)
		buf[0] = base[0];
	while (n)
	{
		buf[--len] = base[n % radix];
		n /= radix;
	}
}

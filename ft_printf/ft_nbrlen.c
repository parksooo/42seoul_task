/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:08:07 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/29 12:42:39 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(size_t n, int radix)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= radix;
	}
	return (len);
}

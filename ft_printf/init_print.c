/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:02 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/28 14:47:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_print_type(int (*type [])(va_list))
{
	int	i;

	i = 0;
	while (i < 256)
		type[i++] = 0;
	type['c'] = print_character;
	type['s'] = print_string;
	type['p'] = print_address;
	type['d'] = print_demical;
	type['i'] = print_demical;
	type['u'] = print_unsigned_demical;
	type['x'] = print_lower_hexademical;
	type['X'] = print_upper_hexademical;
	type['%'] = print_percent;
}

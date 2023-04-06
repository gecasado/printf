/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:02:39 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 16:40:42 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_while(t_data *x)
{
	while (--(x->width) > 0)
	{
		if (x->flag == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		x->len++;
	}
}

void	c_conversion(t_data *x)
{
	char	arg[2];

	if (x->type == '%')
		arg[0] = '%';
	else
		arg[0] = va_arg(x->ap, int);
	arg[1] = '\0';
	if (arg[0] == '\0')
	{
		if (x->flag == '-')
			write(1, "\0", 1);
		else
			x->flag = 0;
		ft_while(x);
		if (x->flag != '-')
			write(1, "\0", 1);
		else
			x->flag = 0;
		x->len++;
	}
	x->raw_str = arg;
}

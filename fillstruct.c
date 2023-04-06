/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:36:40 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 16:39:43 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(t_data *x)
{
	while (*x->format == '0' || *x->format == '-')
	{
		if (*x->format == '-')
			x->flag = '-';
		else if (x->flag != '-')
			x->flag = '0';
		x->format++;
	}
}

void	get_width(t_data *x)
{
	if (*x->format == '*')
	{
		x->format++;
		x->width = va_arg(x->ap, int);
		if (x->width < 0)
		{
			x->width *= -1;
			x->flag = '-';
		}
	}
	if (ft_isdigit(*x->format))
	{
		x->width = *x->format++ - 48;
		while (ft_isdigit(*x->format))
			x->width = x->width * 10 + *x->format++ - 48;
	}
}

void	get_precision(t_data *x)
{
	if (*x->format == '.')
	{
		x->format++;
		if (*x->format == '*')
		{
			x->format++;
			x->precision = va_arg(x->ap, int);
			if (x->precision < 0)
				x->precision = -1;
		}
		if (ft_isdigit(*x->format))
		{
			x->precision = *x->format++ - 48;
			while (ft_isdigit(*x->format))
				x->precision = x->precision * 10 + *x->format++ - 48;
		}
	}
	else
		x->precision = -1;
}

void	get_type(t_data *x)
{
	char	conver[10];
	int		i;

	i = 0;
	ft_strlcpy(conver, "cspdiuxX%", sizeof(conver));
	while (conver[i])
	{
		if (*x->format == conver[i])
			x->type = conver[i];
		i++;
	}
	if (x->type == 'i')
		x->type = 'd';
}

void	fillstruct(t_data *x)
{
	x->raw_alloc = 0;
	get_flag(x);
	get_width(x);
	get_precision(x);
	get_type(x);
	if (x->type == 'c' || x->type == '%')
		c_conversion(x);
	else if (x->type == 's')
		s_conversion(x);
	else if (x->type == 'p')
		p_conversion(x);
	else if (x->type == 'x' || x->type == 'X')
		x_conversion(x);
	else if (x->type == 'd' || x->type == 'u' || x->type == 'i')
		d_i_u_conversion(x);
	else
		NULL;
	fill_final_str(x);
	if (*x->format != '\0')
		x->format++;
}

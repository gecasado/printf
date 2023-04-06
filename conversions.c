/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:34:48 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 16:42:30 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_conversion(t_data *x)
{
	x->raw_str = va_arg(x->ap, char *);
	if (x->raw_str)
		x->raw_str_len = (int)ft_strlen(x->raw_str);
	if (x->precision != -1 && x->precision < x->raw_str_len)
	{
		x->raw_str = ft_substr(x->raw_str, 0, x->precision);
		x->raw_alloc = 1;
	}
}

void	p_conversion(t_data *x)
{
	int		i;

	i = 0;
	x->raw_alloc = 1;
	x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned long int), 16);
	while (x->raw_str[i])
	{
		x->raw_str[i] = ft_tolower(x->raw_str[i]);
		i++;
	}
	if (x->raw_str[0] == '0' && x->raw_str[i] == '\0' && x->precision == 0)
		x->raw_str = ft_strjoin_free(x->raw_str, "x", 1);
	else
	{
		if (x->precision > 0 && x->raw_str != NULL)
		{
			i = x->precision - i;
			while (i-- > 0)
				x->raw_str = ft_strjoin_free("0", x->raw_str, 2);
		}
		x->raw_str = ft_strjoin_free("0x", x->raw_str, 2);
	}
}

void	x_conversion(t_data *x)
{
	int	i;

	i = 0;
	if (x->precision > 0 || (x->precision == -1))
		x->raw_alloc = 1;
	else
		x->raw_alloc = 0;
	if (x->precision != 0)
		x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned int), 16);
	while (x->type == 'x' && x->raw_str[i])
	{
		x->raw_str[i] = ft_tolower(x->raw_str[i]);
		i++;
	}
	i = ft_strlen(x->raw_str);
	while (x->precision > i++)
		x->raw_str = ft_strjoin_free("0", x->raw_str, 2);
	if (x->is_negative == 1)
		x->raw_str = ft_strjoin_free("-", x->raw_str, 2);
}

void	d_i_u_conversion(t_data *x)
{
	int		raw_str_len;
	int		i;

	if (x->precision > 0 || x->precision == -1)
	{
		x->raw_alloc = 1;
		if (x->type == 'd')
			x->raw_str = ft_itoa_minus(va_arg(x->ap, int), x);
		else if (x->type == 'u')
			x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned int), 10);
		raw_str_len = ft_strlen(x->raw_str);
		i = x->precision;
		while (i-- > raw_str_len)
			x->raw_str = ft_strjoin_free("0", x->raw_str, 2);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:18:19 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 18:41:00 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_data
{
	va_list	ap;
	char	*format;
	char	flag;
	int		width;
	int		precision;
	int		len;
	char	type;
	char	*raw_str;
	int		raw_str_len;
	char	*final_str;
	int		is_negative;
	int		raw_alloc;

}				t_data;

int				ft_printf(const char *format, ...);
void			fillstruct(t_data *x);
void			s_conversion(t_data *x);
void			c_conversion(t_data *x);
void			s_conversion(t_data *x);
void			d_i_u_conversion(t_data *x);
void			p_conversion(t_data *x);
void			x_conversion(t_data *x);
void			fill_final_str(t_data *x);
char			*ft_itoa_minus(int n, t_data *x);

#endif

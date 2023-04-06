/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:36:18 by gecasado          #+#    #+#             */
/*   Updated: 2021/03/09 19:32:51 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	unsigned long	limits;
	int				negative;

	negative = 1;
	res = 0;
	limits = (unsigned long)(9223372036854775807 / 10);
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((res > limits || (res == limits && (*str - '0') > 7))
			&& negative == 1)
			return (-1);
		else if ((res > limits || (res == limits && (*str - '0') > 8))
			&& negative == -1)
			return (0);
		res = res * 10 + (*str - 48);
		++str;
	}
	return ((int)res * negative);
}

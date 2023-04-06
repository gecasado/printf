/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:20:20 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 16:17:07 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	is_neg(long int nb, t_data *x)
{
	if (nb < 0)
	{
		x->is_negative = 1;
		return (nb * -1);
	}
	else
	{
		x->is_negative = 0;
		return (nb);
	}
}

char	*ft_itoa_minus(int n, t_data *x)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	nb = is_neg(nb, x);
	if (nb != 0)
	{
		i = ft_numlen(nb, 10);
		str = malloc(i * sizeof(char) + 1);
		if (!str)
			return (0);
		str[i--] = 0;
		while (nb > 0)
		{
			str[i--] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	else
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = 48;
	}
	return (str);
}

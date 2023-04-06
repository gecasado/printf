/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:33:51 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 18:34:58 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long int value, int base)
{
	int					size;
	unsigned long int	number;
	char				*result;
	char				*base_characters;

	number = value;
	base_characters = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_numlen(number, base);
	result = (char *)malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	result[0] = '0';
	while (number > 0)
	{
		result[size--] = base_characters[number % base];
		number /= base;
	}
	return (result);
}

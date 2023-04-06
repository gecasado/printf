/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:35:18 by gecasado          #+#    #+#             */
/*   Updated: 2021/02/13 18:04:47 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *orig, int c, size_t n)
{
	char	*source;
	char	*dst;
	size_t	i;

	source = (char *)orig;
	dst = (char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		if (source[i] == (char)c || dst[i] == (char)c)
		{
			return (dest + (++i));
		}
		i++;
	}
	return (NULL);
}

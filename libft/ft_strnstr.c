/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:44:02 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 17:57:13 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j] && (i + ft_strlen(little)) <= len)
		{
			while (little[j] == big[i + j] && little[j] != '\0')
				j++;
			if (j == ft_strlen(little))
				return ((char *)&(big[i]));
		}
		i++;
	}
	return (NULL);
}

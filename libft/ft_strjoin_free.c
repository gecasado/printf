/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:37:08 by gecasado          #+#    #+#             */
/*   Updated: 2021/05/12 18:37:22 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int to_free)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (to_free & 1)
		free((void **)s1);
	if (to_free & 2)
		free((void **)s2);
	return (res);
}

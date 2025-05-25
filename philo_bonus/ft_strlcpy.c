/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:47:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 16:49:32 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	size_t	srclen;

	cont = 0;
	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (cont < srclen && cont < dstsize - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = 0;
	}
	return (srclen);
}

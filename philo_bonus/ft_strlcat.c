/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:59:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 16:43:51 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	cont;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	cont = 0;
	if (dstsize == 0)
		return (srclen);
	while (dstlen + cont < dstsize - 1 && src[cont] != '\0')
	{
		dst[dstlen + cont] = src[cont];
		cont++;
	}
	dst[dstlen + cont] = '\0';
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
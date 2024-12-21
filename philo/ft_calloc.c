/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:42:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 03:50:50 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cont;
	char	*str;

	str = (char *)s;
	cont = 0;
	while (cont < n)
	{
		str[cont] = 0;
		cont++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*punt;

	punt = malloc(count * size);
	if (punt)
	{
		ft_bzero(punt, count * size);
		return (punt);
	}
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:46:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/20 19:47:07 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	long	num;
	int		cont;
	int		mult;

	num = 0;
	cont = 0;
	mult = 1;
	while (str[cont] == ' ' || (str[cont] >= '\t' && str[cont] <= '\r'))
		cont++;
	if (str[cont] == '-')
		mult = -1;
	if (str[cont] == '-' || str[cont] == '+')
		cont++;
	while (ft_isdigit(str[cont]))
	{
		num = num * 10 + (str[cont] - 48);
		cont++;
	}
	return (num * mult);
}

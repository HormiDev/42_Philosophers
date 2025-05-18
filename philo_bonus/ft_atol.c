/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:46:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/18 03:13:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

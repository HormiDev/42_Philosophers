/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:16:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/18 23:28:06 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (ft_printerror(2));
			j++;
		}
		if (ft_atol(argv[i]) <= 0)
			return (ft_printerror(3));
		i++;
	}
	return (0);
}

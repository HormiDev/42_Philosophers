/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_processes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:44:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/23 03:02:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_processes(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time() + (10 * table->n_philos);
	table->philo_time_to_die = table->time_to_die + table->start_time;
	while (i < table->n_philos)
	{
		table->philos[i] = fork();
		if (table->philos[i] == -1)
		{
			ft_clean_table(table);
			exit(ft_printerror(5));
		}
		if (table->philos[i] == 0)
		{
			table->id = i + 1;
			ft_philo(table);
			exit(0);
		}
		i++;
	}
}

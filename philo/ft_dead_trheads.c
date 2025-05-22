/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_trheads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:00:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/21 22:40:56 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead_trheads(t_table *table)
{
	t_philo	*philo;
	//long	i;

	philo = table->philos;
	while (table->ends < table->n_philos)
	{
		if (philo->is_sleep)
		{
			if (pthread_detach(philo->thread) == 0)
				philo->is_sleep = 0;
			//printf("philo %ld is dead\n", philo->id);
			philo = philo->next;
			pthread_mutex_lock(&table->ends_mutex);
			table->ends++;
			pthread_mutex_unlock(&table->ends_mutex);
		}
	}
	/*
	while (table->ends < table->n_philos)
		usleep(100);
	i = 0;
	while (i < table->n_philos && philo->is_sleep == 0)
	{
		pthread_detach(philo->thread);
		philo = philo->next;
		i++;
	}*/
}

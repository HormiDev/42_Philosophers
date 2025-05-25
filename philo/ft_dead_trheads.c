/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_trheads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:00:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 11:32:12 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead_trheads(t_table *table)
{
	t_philo	*philo;
	long	i;

	philo = table->philos;
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&philo->sleep_mutex);
		if (philo->is_sleep)
		{
			if (pthread_join(philo->thread, 0) == 0)
			{
				philo->is_sleep = 0;
				pthread_mutex_unlock(&philo->sleep_mutex);
				philo = philo->next;
				i++;
			}
		}
		else
			pthread_mutex_unlock(&philo->sleep_mutex);
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

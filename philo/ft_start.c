/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:37:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 00:10:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start(t_table *table)
{
	t_philo	*philo;

	philo = table->philos;
	pthread_mutex_lock(&table->ends_mutex);
	while (table->ends < table->n_philos)
	{
		pthread_mutex_unlock(&table->ends_mutex);
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->time_to_die < ft_get_time() && philo->n_times != table->n_times)
		{
			pthread_mutex_lock(&table->deads_mutex);
			table->deads++;
			pthread_mutex_unlock(&table->deads_mutex);
			//pthread_detach(philo->thread);
			ft_print_status(philo, DEAD);
			break ;
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		philo = philo->next;
		pthread_mutex_lock(&table->ends_mutex);
	}
	pthread_mutex_unlock(&table->ends_mutex);
	pthread_mutex_lock(&table->ends_mutex);
	table->ends = 0;
	pthread_mutex_unlock(&table->ends_mutex);
	//while (table->ends < table->n_philos)
	//	usleep(100);
}

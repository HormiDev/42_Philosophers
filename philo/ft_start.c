/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:37:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 14:33:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_is_dead(t_philo *philo, t_table *table)
{
	pthread_mutex_unlock(&philo->n_times_mutex);
	pthread_mutex_lock(&table->deads_mutex);
	table->deads++;
	pthread_mutex_unlock(&table->deads_mutex);
	ft_print_status(philo, DEAD);
	pthread_mutex_unlock(&philo->eat_mutex);
}

void	ft_start(t_table *table)
{
	t_philo	*philo;

	philo = table->philos;
	while (1)
	{
		pthread_mutex_lock(&table->ends_mutex);
		if (!(table->ends < table->n_philos))
		{
			pthread_mutex_unlock(&table->ends_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->ends_mutex);
		pthread_mutex_lock(&philo->eat_mutex);
		pthread_mutex_lock(&philo->n_times_mutex);
		if (philo->time_to_die < ft_get_time()
			&& philo->n_times != table->n_times)
		{
			ft_is_dead(philo, table);
			break ;
		}
		pthread_mutex_unlock(&philo->n_times_mutex);
		pthread_mutex_unlock(&philo->eat_mutex);
		philo = philo->next;
	}
}

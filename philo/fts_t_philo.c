/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:15:53 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 10:41:09 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_new_philo(long id)
{
	t_philo	*new;

	new = ft_calloc(1, sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	pthread_mutex_init(&new->fork, NULL);
	pthread_mutex_init(&new->eat_mutex, NULL);
	pthread_mutex_init(&new->sleep_mutex, NULL);
	pthread_mutex_init(&new->n_times_mutex, NULL);
	new->next = NULL;
	return (new);
}

t_philo	*ft_last_philo(t_philo *philo)
{
	t_philo	*last;

	last = philo;
	while (last && last->next)
		last = last->next;
	return (last);
}

void	ft_add_philo(t_philo **philo, t_philo *new)
{
	t_philo	*last;

	if (!*philo)
	{
		*philo = new;
		return ;
	}
	last = ft_last_philo(*philo);
	last->next = new;
}

void	ft_clean_philos(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*initial_philo;

	initial_philo = philo;
	philo = philo->next;
	while (philo != initial_philo && philo->next)
	{
		tmp = philo;
		philo = philo->next;
		pthread_mutex_destroy(&tmp->fork);
		pthread_mutex_destroy(&tmp->eat_mutex);
		pthread_mutex_destroy(&tmp->sleep_mutex);
		free(tmp);
	}
	pthread_mutex_destroy(&initial_philo->fork);
	pthread_mutex_destroy(&initial_philo->eat_mutex);
	pthread_mutex_destroy(&initial_philo->sleep_mutex);
	pthread_mutex_destroy(&initial_philo->n_times_mutex);
	free(initial_philo);
}

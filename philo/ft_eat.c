/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:34:50 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 15:36:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat_routine(t_philo *philo)
{
	ft_print_status(philo, EAT);
	while (ft_get_time() < philo->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->deads_mutex);
		if (philo->table->deads != 0)
		{
			pthread_mutex_unlock(&philo->table->deads_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->deads_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	ft_eat(t_philo *philo)
{
	if (&philo->fork < &philo->next->fork)
	{
		pthread_mutex_lock(&philo->fork);
		ft_print_status(philo, TAKE);
		pthread_mutex_lock(&philo->next->fork);
		ft_print_status(philo, TAKE);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		ft_print_status(philo, TAKE);
		pthread_mutex_lock(&philo->fork);
		ft_print_status(philo, TAKE);
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->time_to_die = ft_get_time() + philo->table->time_to_die;
	pthread_mutex_unlock(&philo->eat_mutex);
	philo->time_to_eat = ft_get_time() + philo->table->time_to_eat;
	ft_eat_routine(philo);
}

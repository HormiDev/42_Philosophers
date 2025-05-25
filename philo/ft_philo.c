/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:55:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 13:41:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_print_status(philo, EAT);
	while (ft_get_time() < philo->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->deads_mutex);
		if (philo->table->deads != 0)
		{
			pthread_mutex_unlock(&philo->table->deads_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->table->deads_mutex);
		usleep(1);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	ft_one_philo(t_philo *philo)
{
	while (philo->table->start_time > ft_get_time())
		usleep(1);
	ft_print_status(philo, TAKE);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->time_to_die = ft_get_time() + philo->table->time_to_die;
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_lock(&philo->sleep_mutex);
	philo->is_sleep = 1;
	pthread_mutex_unlock(&philo->sleep_mutex);
}

void	*ft_philo(void *philo_void)
{
	t_philo	*philo;
	t_table	*table;
	long	start_sleep;

	philo = (t_philo *)philo_void;
	table = philo->table;
	if (philo->table->n_philos == 1)
		return (ft_one_philo(philo), NULL);
	while (table->start_time > ft_get_time())
		usleep(1);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->time_to_die = ft_get_time() + table->time_to_die;
	pthread_mutex_unlock(&philo->eat_mutex);
	if (philo->id % 2 != 0)
		usleep(table->time_to_eat / 2 * 1000);
	while (philo->n_times < table->n_times || table->n_times == -1)
	{
		pthread_mutex_lock(&table->deads_mutex);
		if (table->deads != 0)
		{
			pthread_mutex_unlock(&table->deads_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->deads_mutex);
		ft_eat(philo);
		ft_print_status(philo, SLEEP);
		pthread_mutex_lock(&philo->sleep_mutex);
		philo->is_sleep = 1;
		pthread_mutex_unlock(&philo->sleep_mutex);
		start_sleep = ft_get_time();
		while(1)
		{
			pthread_mutex_lock(&philo->table->deads_mutex);
			if (philo->table->deads != 0)
			{
				pthread_mutex_unlock(&philo->table->deads_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->table->deads_mutex);
			if (table->time_to_sleep - (ft_get_time() - start_sleep) <= 100)
			{
				usleep((table->time_to_sleep - (ft_get_time() - start_sleep)) * 1000);
				break ;
			}
			usleep(1000 * 100);
		}
		pthread_mutex_lock(&philo->table->deads_mutex);
		if (philo->table->deads != 0)
		{
			pthread_mutex_unlock(&philo->table->deads_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->deads_mutex);
		pthread_mutex_lock(&philo->sleep_mutex);
		philo->is_sleep = 0;
		pthread_mutex_unlock(&philo->sleep_mutex);
		ft_print_status(philo, THINK);
		pthread_mutex_lock(&philo->n_times_mutex);
		philo->n_times++;
		pthread_mutex_unlock(&philo->n_times_mutex);
	}
	pthread_mutex_lock(&philo->table->ends_mutex);
	philo->table->ends++;
	pthread_mutex_unlock(&philo->table->ends_mutex);
	pthread_mutex_lock(&philo->sleep_mutex);
	philo->is_sleep = 1;
	pthread_mutex_unlock(&philo->sleep_mutex);
	return (NULL);
}

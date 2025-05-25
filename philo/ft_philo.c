/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:55:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 15:35:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static int	ft_sleep(t_table *table, t_philo *philo)
{
	long	start_sleep;

	ft_print_status(philo, SLEEP);
	pthread_mutex_lock(&philo->sleep_mutex);
	philo->is_sleep = 1;
	pthread_mutex_unlock(&philo->sleep_mutex);
	start_sleep = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&philo->table->deads_mutex);
		if (philo->table->deads != 0)
		{
			pthread_mutex_unlock(&philo->table->deads_mutex);
			return (-1);
		}
		pthread_mutex_unlock(&philo->table->deads_mutex);
		if (table->time_to_sleep - (ft_get_time() - start_sleep) <= 100)
		{
			usleep((table->time_to_sleep - (ft_get_time() - start_sleep))
				* 1000);
			break ;
		}
		usleep(1000 * 100);
	}
	return (0);
}

static int	ft_while_rutine(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->deads_mutex);
	if (table->deads != 0)
	{
		pthread_mutex_unlock(&table->deads_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->deads_mutex);
	ft_eat(philo);
	if (ft_sleep(table, philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->table->deads_mutex);
	if (philo->table->deads != 0)
	{
		pthread_mutex_unlock(&philo->table->deads_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->table->deads_mutex);
	pthread_mutex_lock(&philo->sleep_mutex);
	philo->is_sleep = 0;
	pthread_mutex_unlock(&philo->sleep_mutex);
	ft_print_status(philo, THINK);
	pthread_mutex_lock(&philo->n_times_mutex);
	philo->n_times++;
	pthread_mutex_unlock(&philo->n_times_mutex);
	return (0);
}

static void	ft_end_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->ends_mutex);
	philo->table->ends++;
	pthread_mutex_unlock(&philo->table->ends_mutex);
	pthread_mutex_lock(&philo->sleep_mutex);
	philo->is_sleep = 1;
	pthread_mutex_unlock(&philo->sleep_mutex);
}

void	*ft_philo(void *philo_void)
{
	t_philo	*philo;
	t_table	*table;
	int		while_rutine;

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
		while_rutine = ft_while_rutine(table, philo);
		if (while_rutine == -1)
			return (NULL);
		else if (while_rutine == 1)
			break ;
	}
	ft_end_routine(philo);
	return (NULL);
}

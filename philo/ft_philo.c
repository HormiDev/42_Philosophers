/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:55:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 04:32:32 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	int	forks[2];

	forks[0] = 1;
	forks[1] = 1;
	while (forks[0] != 0 && forks[1] != 0)
	{
		if (forks[0] != 0)
		{
			forks[0] = pthread_mutex_lock(&philo->fork);
			if (forks[0] != 0)
				ft_print_status(philo, TAKE);
		}
		if (forks[1] != 0)
		{
			forks[1] = pthread_mutex_lock(&philo->next->fork);
			if (forks[1] != 0)
				ft_print_status(philo, TAKE);
		}
		usleep(1);
	}
	ft_print_status(philo, EAT);
	philo->time_to_die = ft_get_time() + philo->table->time_to_die;
	philo->time_to_eat = ft_get_time() + philo->table->time_to_eat;
	while (ft_get_time() < philo->time_to_eat)
		usleep(1);
}

void	*ft_philo(void *philo_void)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)philo_void;
	table = philo->table;
	while (table->start == 0)
		usleep(1);
	write(1, "prror\n", 6);
	philo->time_to_die = ft_get_time() + table->time_to_die;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->n_times < table->n_times || table->n_times == -1)
	{
		ft_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_print_status(philo, SLEEP);
		usleep(table->time_to_sleep * 1000);
		ft_print_status(philo, THINK);
		philo->n_times++;
	}
	philo->table->ends++;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:55:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/16 16:07:56 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print_status(philo, TAKE);
	pthread_mutex_lock(&philo->next->fork);
	ft_print_status(philo, TAKE);
	philo->time_to_die = ft_get_time() + philo->table->time_to_die;
	philo->time_to_eat = ft_get_time() + philo->table->time_to_eat;
	ft_print_status(philo, EAT);
	while (ft_get_time() < philo->time_to_eat && philo->table->deads == 0)
		usleep(1);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*ft_philo(void *philo_void)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)philo_void;
	table = philo->table;
	while (table->start == 0)
		usleep(100);
	philo->time_to_die = ft_get_time() + table->time_to_die;
	if (philo->id % 2 == 0)
		usleep(table->time_to_eat / 2 * 1000);
	while ((philo->n_times < table->n_times || table->n_times == -1) && table->deads == 0)
	{
		ft_eat(philo);
		ft_print_status(philo, SLEEP);
		usleep(table->time_to_sleep * 1000);
		ft_print_status(philo, THINK);
		philo->n_times++;
	}
	pthread_mutex_lock(&table->ends_mutex);
	philo->table->ends++;
	printf("Ends: %ld\n", philo->table->ends);
	pthread_mutex_unlock(&table->ends_mutex);
	return (NULL);
}

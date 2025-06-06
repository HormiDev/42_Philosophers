/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:49:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/26 00:32:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*ft_monitor(void *table_void)
{
	t_table	*table;

	table = (t_table *)table_void;
	while (1)
	{
		sem_wait(table->semutex[table->id - 1].sem);
		if (table->philo_time_to_die < ft_get_time())
		{
			ft_print_status(table, DEAD);
			free(table->philos);
			free(table);
			free(table->semutex);
			exit(1);
		}
		sem_post(table->semutex[table->id - 1].sem);
		usleep(100);
	}
}

static void	ft_while_rutine(t_table *table)
{
	sem_wait(table->forks);
	ft_print_status(table, TAKE);
	sem_wait(table->forks);
	ft_print_status(table, TAKE);
	sem_wait(table->semutex[table->id - 1].sem);
	table->philo_time_to_die = ft_get_time() + table->time_to_die;
	sem_post(table->semutex[table->id - 1].sem);
	ft_print_status(table, EAT);
	usleep(table->time_to_eat * 1000);
	sem_post(table->forks);
	sem_post(table->forks);
	ft_print_status(table, SLEEP);
	usleep(table->time_to_sleep * 1000);
	ft_print_status(table, THINK);
	if (table->n_times > 0)
		table->n_times--;
}

void	ft_philo(t_table *table)
{
	table->philo_time_to_die = table->start_time + table->time_to_die;
	pthread_create(&table->monitor, NULL, ft_monitor, (void *)table);
	while (table->start_time > ft_get_time())
		usleep(1);
	if (table->id % 2 == 0)
		usleep(table->time_to_eat / 2 * 1000);
	while (table->n_times != 0)
		ft_while_rutine(table);
	pthread_detach(table->monitor);
	free(table->philos);
	free(table->semutex);
	free(table);
}

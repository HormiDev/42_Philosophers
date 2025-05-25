/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:25:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 13:21:58 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_table	*ft_loading(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		exit(ft_printerror(4));
	table->n_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->n_times = ft_atol(argv[5]);
	else
		table->n_times = -1;
	table->philos = ft_calloc(table->n_philos, sizeof(pid_t));
	if (!table->philos)
	{
		free(table);
		exit(ft_printerror(4));
	}
	sem_unlink("forks");
	sem_unlink("print");
	table->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, table->n_philos);
	table->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (table->forks == SEM_FAILED || table->print == SEM_FAILED)
	{
		free(table->philos);
		free(table);
		exit(ft_printerror(6));
	}
	return (table);
}


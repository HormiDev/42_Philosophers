/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_trheads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:45:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 14:38:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_trheads(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = table->philos;
	while (i < table->n_philos)
	{
		printf("Creating thread %d\n", i);
		pthread_create(&philo->thread, NULL, &(ft_philo), (void *)philo);
		printf("Thread %d created\n", i);
		philo = philo->next;
		i++;
	}
	usleep(10000);
}

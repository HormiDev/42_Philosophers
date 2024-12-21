/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_trheads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:00:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 04:45:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead_trheads(t_table *table)
{
	t_philo	*philo;
	long	i;

	i = 0;
	philo = table->philos;
	while (i < table->n_philos)
	{
		pthread_detach(philo->thread);
		philo = philo->next;
		i++;
	}
}

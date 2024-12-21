/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:37:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 20:38:36 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start(t_table *table)
{
	t_philo	*philo;

	philo = table->philos;
	table->start_time = ft_get_time();
	table->start = 1;
	while (table->ends < table->n_philos)
	{
		if (philo->time_to_die < ft_get_time())
		{
			pthread_detach(philo->thread);
			ft_print_status(philo, DEAD);
			break ;
		}
		philo = philo->next;
	}
}

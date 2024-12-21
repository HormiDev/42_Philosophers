/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:37:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 04:45:28 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start(t_table *table)
{
	t_philo	*philo;

	philo = table->philos;
	table->start = 1;
	while (table->ends < table->n_philos)
	{
		if (philo->time_to_die < ft_get_time())
		{
			ft_print_status(philo, DEAD);
			break ;
		}
		philo = philo->next;
	}
}

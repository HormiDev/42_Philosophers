/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_trheads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:45:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/18 23:28:12 by ide-dieg         ###   ########.fr       */
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
		pthread_create(&philo->thread, NULL, &(ft_philo), (void *)philo);
		philo = philo->next;
		i++;
	}
}

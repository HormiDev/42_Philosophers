/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:23:24 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/22 12:38:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status_2(t_philo *philo, int status)
{
	if (status == 1)
		printf("%ld [%ld]" ORANGE " has taken a fork\n" N,
			ft_get_time() - philo->table->start_time, philo->id);
	else if (status == 2)
		printf("%ld [%ld]" GREN " is eating\n" N,
			ft_get_time() - philo->table->start_time, philo->id);
	else if (status == 3)
		printf("%ld [%ld]" PINK " is sleeping\n" N,
			ft_get_time() - philo->table->start_time, philo->id);
	else if (status == 4)
		printf("%ld [%ld]" CYAN " is thinking\n" N,
			ft_get_time() - philo->table->start_time, philo->id);
	else if (status == 5)
	{
		printf("%ld [%ld]" RED " died\n" N,
			ft_get_time() - philo->table->start_time, philo->id);
		philo->table->deads++;
	}
}

void	ft_print_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->table->print);
	if (philo->table->deads == 0)
		ft_print_status_2(philo, status);
	if (status != DEAD)
		pthread_mutex_unlock(&philo->table->print);
}

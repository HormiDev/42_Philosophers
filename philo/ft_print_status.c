/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:23:24 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 14:42:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, int status)
{
	int	mutex;

	mutex = 1;
	while (mutex != 0)
	{
		mutex = pthread_mutex_lock(&philo->table->print);
		usleep(1);
	}
	if (philo->table->deads == 0)
	{
		if (status == 1)
			printf("%ld [%ld]" ORANGE " has taken a fork\n" N, ft_get_time(), philo->id);
		else if (status == 2)
			printf("%ld [%ld]" GREN " is eating\n" N, ft_get_time(), philo->id);
		else if (status == 3)
			printf("%ld [%ld] is sleeping\n", ft_get_time(), philo->id);
		else if (status == 4)
			printf("%ld [%ld]" CYAN " is thinking\n" N, ft_get_time(), philo->id);
		else if (status == 5)
		{
			printf("%ld [%ld]" RED " died\n" N, ft_get_time(), philo->id);
			philo->table->deads++;
		}
	}
	pthread_mutex_unlock(&philo->table->print);
}

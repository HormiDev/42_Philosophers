/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:06:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 16:57:07 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clean_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	ft_kill_pids(table);
	sem_close(table->forks);
	sem_unlink("forks");
	sem_close(table->print);
	sem_unlink("print");
	if (table->semutex)
	{
		i = 0;
		while (i < table->n_philos)
		{
			sem_close(table->semutex[i].sem);
			sem_unlink(table->semutex[i].sem_name);
			i++;
		}
		free(table->semutex);
	}
	if (table->philos)
		free(table->philos);
	free(table);
}

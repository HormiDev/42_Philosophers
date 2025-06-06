/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_pids.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:43:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 17:04:13 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill_pids(t_table *table)
{
	int	i;

	i = 0;
	if (!table || !table->philos)
		return ;
	while (i < table->n_philos)
	{
		if (table->philos[i] > 0)
			kill(table->philos[i], SIGKILL);
		i++;
	}
}

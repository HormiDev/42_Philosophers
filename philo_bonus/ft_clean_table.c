/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:06:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/23 03:00:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clean_table(t_table *table)
{
	ft_kill_pids(table);
	sem_close(table->forks);
	sem_unlink("forks");
	sem_close(table->print);
	sem_unlink("print");
	free(table->philos);
	free(table);
}

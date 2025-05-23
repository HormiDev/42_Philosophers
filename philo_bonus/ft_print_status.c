/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:23:24 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/23 03:17:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_status(t_table *table, int status)
{
	sem_wait(table->print);
		if (status == 1)
			printf("%ld [%d]%s has taken a fork%s\n",
				ft_get_time() - table->start_time, table->id, ORANGE, N);
		else if (status == 2)
			printf("%ld [%d]%s is eating%s\n",
				ft_get_time() - table->start_time, table->id, GREN, N);
		else if (status == 3)
			printf("%ld [%d]%s is sleeping%s\n",
				ft_get_time() - table->start_time, table->id, PINK, N);
		else if (status == 4)
			printf("%ld [%d]%s is thinking%s\n",
				ft_get_time() - table->start_time, table->id, CYAN, N);
		else if (status == 5)
		{
			printf("%ld [%d]%s died%s\n",
				ft_get_time() - table->start_time, table->id, RED, N);
			return ;
		}	
	sem_post(table->print);
}

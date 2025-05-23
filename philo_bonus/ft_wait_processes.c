/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:07:42 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/23 03:55:06 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_del_pid(t_table *table, pid_t pid)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (table->philos[i] == pid)
		{
			table->philos[i] = -1;
			break ;
		}
		i++;
	}
}

void	ft_wait_processes(t_table *table)
{
	int	i;
	int	status;
	pid_t	pid;

	i = 0;
	while (i < table->n_philos)
	{
		pid = waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{	
			if (WEXITSTATUS(status) == 1)
			{
				ft_del_pid(table, pid);
				ft_kill_pids(table);
			}	
			else
				ft_del_pid(table, pid);
		}	
		i++;
	}
}

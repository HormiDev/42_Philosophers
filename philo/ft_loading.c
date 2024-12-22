/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:00 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/22 13:13:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table)
{
	if (table->philos)
		ft_clean_philos(table->philos);
	pthread_mutex_destroy(&table->print);
	free(table);
}

void	ft_create_philos(t_table *table)
{
	t_philo	*philo;
	t_philo	*new;
	long	i;

	i = 0;
	philo = NULL;
	while (i < table->n_philos)
	{
		new = ft_new_philo(i + 1);
		if (!new)
		{
			ft_clean(table);
			table = NULL;
			return ;
		}
		new->table = table;
		ft_add_philo(&philo, new);
		i++;
	}
	ft_last_philo(philo)->next = philo;
	table->philos = philo;
}

t_table	*ft_loading(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	ft_parsing(table, argc, argv);
	ft_create_philos(table);
	if (!table->philos)
	{
		ft_clean(table);
		table = NULL;
	}
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->ends_mutex, NULL);
	table->start = 0;
	return (table);
}

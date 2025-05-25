/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:58:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 17:07:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		return (ft_printerror(1));
	if (ft_check_arguments(argc, argv))
		return (1);
	table = ft_loading(argc, argv);
	if (!table)
		return (ft_printerror(4));
	ft_create_processes(table);
	ft_wait_processes(table);
	ft_clean_table(table);
	return (0);
}

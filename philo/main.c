/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:08:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 20:59:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_create_trheads(table);
	ft_start(table);
	ft_dead_trheads(table);
	ft_clean(table);
	return (0);
}

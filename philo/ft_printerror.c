/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:09:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/21 00:34:43 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_printerror(int error_code)
{
	write(2, RED, ft_strlen(RED));
	write(2, "Error:\n", 7);
	write(2, ORANGE, ft_strlen(ORANGE));
	if (error_code == 1)
	{
		write(2, "Use: ./pilo <number_of_philosophers> <time_to_die> ", 52);
		write(2, " <time_to_eat> <time_to_sleep> ", 31);
		write(2, "[number_of_times_each_philosopher_must_eat]\n", 45);
	}
	else if (error_code == 2)
		write(2, "Arguments must be numbers\n", 27);
	else if (error_code == 3)
		write(2, "Arguments must be greater than 0\n", 34);
	else if (error_code == 4)
		write(2, "Malloc error\n", 13);
	write(2, N, ft_strlen(N));
	return (1);
}
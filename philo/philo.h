/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:08:01 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/21 20:27:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define N "\033[0m"
# define RED "\033[31m"
# define GREN "\033[32m"
# define ORANGE "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define CYAN "\033[36m"

# define TAKE 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				is_sleep;
	long			id;
	long			time_to_die;
	long			time_to_eat;
	long			n_times;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	long			n_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_times;
	long			ends;
	pthread_mutex_t	ends_mutex;
	pthread_mutex_t	deads_mutex;
	long			deads;
	pthread_mutex_t	start;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	print;
}	t_table;

int		ft_check_arguments(int argc, char **argv);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_strlen(char *str);
int		ft_printerror(int error_code);
void	ft_parsing(t_table *table, int argc, char **argv);
t_table	*ft_loading(int argc, char **argv);
void	ft_clean(t_table *table);
void	*ft_calloc(size_t count, size_t size);
t_philo	*ft_new_philo(long id);
t_philo	*ft_last_philo(t_philo *philo);
void	ft_add_philo(t_philo **philo, t_philo *new);
void	ft_clean_philos(t_philo *philo);
void	ft_create_philos(t_table *table);
void	ft_create_trheads(t_table *table);
void	*ft_philo(void *philo);
long	ft_get_time(void);
void	ft_print_status(t_philo *philo, int status);
void	ft_start(t_table *table);
void	ft_dead_trheads(t_table *table);

#endif
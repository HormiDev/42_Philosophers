/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:08:01 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 16:50:36 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct s_semutex
{
	char	sem_name[20];
	sem_t	*sem;
}	t_semutex;

typedef struct s_table
{
	int				id;
	long			n_philos;
	long			time_to_die;
	long			philo_time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_times;
	long			start_time;
	pid_t			*philos;
	sem_t			*forks;
	sem_t			*print;
	t_semutex		*semutex;
	pthread_t		monitor;
}	t_table;

int		ft_check_arguments(int argc, char **argv);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);
int		ft_printerror(int error_code);
void	*ft_calloc(size_t count, size_t size);
void	ft_create_processes(t_table *table);
void	ft_philo(t_table *table);
void	ft_print_status(t_table *table, int status);
void	ft_wait_processes(t_table *table);
void	ft_clean_table(t_table *table);
void	ft_kill_pids(t_table *table);
long	ft_get_time(void);
t_table	*ft_loading(int argc, char **argv);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_itoa(int n);

#endif
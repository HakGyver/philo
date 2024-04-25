/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:00:29 by jteste            #+#    #+#             */
/*   Updated: 2024/04/25 16:57:32 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
// gettimeofday
# include <pthread.h>
// pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy,
// pthread_mutex_lock, pthread_mutex_unlock
# include <stdlib.h>
// malloc, free
# include <stdio.h>
// printf
# include <unistd.h>
// write, usleep
# include <string.h>
// memset
# include <stdbool.h>
// bool type, true, false
# include <limits.h>
// implementation limits

typedef struct s_table t_table;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				meals_eaten;
	size_t			last_meal;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	size_t			start_time;
	int				nb_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat;
	bool			death;
	pthread_t		supervisor;
	t_philo			**philos;
}	t_table;

int		ft_atoi(const char *str);
bool	check_args(char const **argv);
bool	all_num(char const *str);
void	base_init(t_table *table, char const **argv);
size_t	start_time(void);
size_t	elapsed_time(size_t start);

#endif
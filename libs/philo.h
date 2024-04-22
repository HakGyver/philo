/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:00:29 by jteste            #+#    #+#             */
/*   Updated: 2024/04/22 16:41:56 by jteste           ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	unsigned int	id;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				must_eat;
	unsigned int	meals_eaten;
}	t_philo;

typedef struct s_table
{
	unsigned int	nb_of_philos;
	t_philo			*philos;
}	t_table;

int		ft_atoi(const char *str);
bool	check_args(char const **argv);
bool	all_num(char const *str);
void	base_init(t_philo *philo, char const **argv);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:00:29 by jteste            #+#    #+#             */
/*   Updated: 2024/05/15 13:19:30 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* -------- Includes -------- */

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

/* -------- Error strings -------- */

# define MALLOC "Failed to allocate memory"
# define ARG_COUNT "Wrong number of argument"
# define PHILO_COUNT "Wrong argument => number of philosopher"
# define TIME_TO_DIE "Wrong argument => time to die"
# define TIME_TO_EAT "Wrong argument => time to eat"
# define TIME_TO_SLEEP "Wrong argument => time to sleep"
# define MEAL_COUNT "Wrong argument => number of time philosophers must eat"
# define MUTEX	"Failed to initialize mutex"
# define GTOD "Error : Gettimeofday() Failed"
# define USLEEP "Error : Usleep() Failed"
# define THREAD_CREATE "Failed to create thread"
# define THREAD_JOIN "Failed to join thread"

/* -------- Philo States -------- */

//Strings
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define EAT "is eating"
# define FORK "has taken a fork"
# define DEATH "died"

//Flags
# define I_SLEEP 0
# define I_THINK 1
# define I_EAT 2
# define I_FORK 3
# define I_DEATH 4

/* -------- Colors -------- */

// Regulars
# define RESET          "\x1B[0m"
# define BLACK          "\x1B[0;30m"
# define RED            "\x1B[0;31m"
# define GREEN          "\x1B[0;32m"
# define YELLOW         "\x1B[0;33m"
# define BLUE           "\x1B[0;34m"
# define MAGENTA        "\x1B[0;35m"
# define CYAN           "\x1B[0;36m"
# define WHITE          "\x1B[0;37m"

// Bolds
# define B_BLACK   "\x1B[1;30m"
# define B_RED     "\x1B[1;31m"
# define B_GREEN   "\x1B[1;32m"
# define B_YELLOW  "\x1B[1;33m"
# define B_BLUE    "\x1B[1;34m"
# define B_MAGENTA "\x1B[1;35m"
# define B_CYAN    "\x1B[1;36m"
# define B_WHITE   "\x1B[1;37m"

// Backgrounds
# define BLACK_BG       "\x1B[40m"
# define RED_BG         "\x1B[41m"
# define GREEN_BG       "\x1B[42m"
# define YELLOW_BG      "\x1B[43m"
# define BLUE_BG        "\x1B[44m"
# define MAGENTA_BG     "\x1B[45m"
# define CYAN_BG        "\x1B[46m"
# define WHITE_BG       "\x1B[47m"

/* -------- Structures -------- */

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	fork;
	bool			is_fork_init;
	pthread_mutex_t	meal_lock;
	bool			is_meal_lock_init;
	int				meals_eaten;
	bool			is_eating;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	time_t			start_time;
	int				nb_of_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	bool			death;
	pthread_t		overseer;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	death_lock;
	t_philo			**philos;
	int				index;
}	t_table;

/* -------- Functions -------- */

// Time (time.c)
time_t	start_time(void);
time_t	elapsed_time(time_t start);
void	better_usleep(time_t milliseconds);

// Free & Error (error_and_free_.c)
bool	error_exit(char *str_error, t_table *table);
void	ft_free_all(t_table *table);
void	destroy_mutex(t_table *table);

// Initialization (inits.c)
bool	check_args(int argc, char const **argv, t_table *table);
bool	table_init(char const **argv, t_table *table);
bool	table_alloc(t_table *table);
bool	philo_init(t_table *table);

// Utilities (utils.c)
int		ft_atoi(const char *str);
bool	all_num(char const *str);
size_t	ft_strlen(char *str);
void	display_state(int state, t_philo *philo);
bool	death_check(t_philo *philo);

// Threads (threads.c)
bool	threads_creation(t_table *table);
bool	threads_join(t_table *table);

// Routines (philo_routine.c, overseer_routine.c)
void	*philo_routine(void *arg);
void	*overseer_routine(void *arg);
void	meal_time(t_philo *philo);
void	bed_time(t_philo *philo);
void	reflexion_time(t_philo *philo);
bool	check_meals(t_table *table);
bool	check_if_philo_is_dead(t_table *table);
bool	is_philo_dead(t_philo *philo);
void	handle_one_philo(t_philo *philo);

#endif
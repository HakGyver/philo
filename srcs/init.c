/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:40:40 by jteste            #+#    #+#             */
/*   Updated: 2024/04/30 12:16:27 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

bool	check_args(char const **argv, t_table *table)
{
	if (ft_atoi(argv[1]) <= 0 || all_num(argv[1]))
		return (error_exit(PHILO_COUNT, table));
	if (ft_atoi(argv[2]) <= 0 || all_num(argv[2]))
		return (error_exit(TIME_TO_DIE, table));
	if (ft_atoi(argv[3]) <= 0 || all_num(argv[3]))
		return (error_exit(TIME_TO_EAT, table));
	if (ft_atoi(argv[4]) <= 0 || all_num(argv[4]))
		return (error_exit(TIME_TO_SLEEP, table));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || all_num(argv[5])))
		return (error_exit(MEAL_COUNT, table));
	return (false);
}

bool	table_init(char const **argv, t_table *table)
{
	table->start_time = start_time();
	table->nb_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	table->death = false;
	if (table_alloc(table))
		return (true);
	if (pthread_mutex_init(&table->death_lock, NULL) != 0)
		return (error_exit(MUTEX, table));
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->death_lock);
		return (error_exit(MUTEX, table));
	}
	return (false);
}

bool	table_alloc(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->nb_of_philos * sizeof(t_philo));
	if (!table->philos)
		return (error_exit(MALLOC, table));
	while (i < table->nb_of_philos)
	{
		table->philos[i] = malloc(1 * sizeof(t_philo));
		if (!table->philos[i])
			return (error_exit(MALLOC, table));
		i++;
	}
	return (false);
}

bool	philo_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philos)
	{
		table->philos[i]->last_meal = start_time();
		table->philos[i]->id = i + 1;
		table->philos[i]->meals_eaten = 0;
		table->philos[i]->table = table;
		if (pthread_mutex_init(&table->philos[i]->fork, NULL) != 0)
		{
			pthread_mutex_destroy(&table->death_lock);
			pthread_mutex_destroy(&table->write_lock);
			while (i--)
				pthread_mutex_destroy(&table->philos[i]->fork);
			return (error_exit(MUTEX, table));
		}
		if (i == 0)
			table->philos[i]->fork_left = &table->philos
			[table->nb_of_philos - 1]->fork;
		else
			table->philos[i]->fork_left = &table->philos[i - 1]->fork;
		i++;
	}
	return (false);
}

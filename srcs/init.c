/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:40:40 by jteste            #+#    #+#             */
/*   Updated: 2024/04/29 12:41:29 by jteste           ###   ########.fr       */
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
		return (error_exit("MUTEX INIT", table));
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
		return (error_exit("MUTEX INIT", table));
	return (false);
}

bool	table_alloc(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->nb_of_philos * sizeof(t_philo));
	while (i < table->nb_of_philos)
	{
		table->philos[i] = malloc(1 * sizeof(t_philo));
		if (!table->philos[i])
			return (error_exit(MALLOC, table));
		i++;
	}
	return (false);
}

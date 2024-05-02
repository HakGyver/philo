/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:13:33 by jteste            #+#    #+#             */
/*   Updated: 2024/05/02 13:21:41 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

bool	threads_creation(t_table *table)
{
	int	i;

	if (pthread_create(&table->overseer, NULL, overseer_routine, table) != 0)
	{
		destroy_mutex(table);
		return (error_exit(THREAD_CREATE, table));
	}
	i = 0;
	while (i < table->nb_of_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				philo_routine, table->philos[i]) == -1)
		{
			destroy_mutex(table);
			return (error_exit(THREAD_CREATE, table));
		}
		i++;
	}
	return (false);
}

bool	threads_join(t_table *table)
{
	int	i;

	if (pthread_join(table->overseer, NULL) != 0)
	{
		destroy_mutex(table);
		return (error_exit(THREAD_JOIN, table));
	}
	i = 0;
	while (i < table->nb_of_philos)
	{
		if (pthread_join(table->philos[i]->thread, NULL) != 0)
		{
			destroy_mutex(table);
			return (error_exit(THREAD_JOIN, table));
		}
		i++;
	}
	return (false);
}

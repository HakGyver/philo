/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:23:41 by jteste            #+#    #+#             */
/*   Updated: 2024/05/02 13:24:56 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->write_lock);
	printf("%lums ==> I'm philo nb [%d]\n",
		elapsed_time(philo->table->start_time), philo->id);
	pthread_mutex_unlock(&philo->table->write_lock);
	return (NULL);
}

void	*overseer_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->write_lock);
	printf("Overseer is supervising %d philos\n", table->nb_of_philos);
	pthread_mutex_unlock(&table->write_lock);
	return (NULL);
}

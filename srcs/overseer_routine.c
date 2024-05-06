/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:54:03 by jteste            #+#    #+#             */
/*   Updated: 2024/05/06 14:54:30 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	*overseer_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->write_lock);
	printf("%lums ==> Overseer is supervising %d philos\n",
		elapsed_time(table->start_time), table->nb_of_philos);
	pthread_mutex_unlock(&table->write_lock);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:23:41 by jteste            #+#    #+#             */
/*   Updated: 2024/05/06 15:30:45 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		better_usleep(1);
	while (!death_check(philo))
	{
		if (!death_check(philo))
			meal_time(philo);
		if (!death_check(philo))
			bed_time(philo);
		if (!death_check(philo))
			reflexion_time(philo);
	}
	return (NULL);
}

void	meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	display_state(I_FORK, philo);
	pthread_mutex_lock(philo->fork_left);
	display_state(I_FORK, philo);
	display_state(I_EAT, philo);
	philo->last_meal = start_time();
	philo->meals_eaten++;
	better_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->fork_left);
	return ;
}

void	bed_time(t_philo *philo)
{
	display_state(I_SLEEP, philo);
	better_usleep(philo->table->time_to_sleep);
	return ;
}

void	reflexion_time(t_philo *philo)
{
	display_state(I_THINK, philo);
	return ;
}

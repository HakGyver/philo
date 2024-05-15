/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:54:03 by jteste            #+#    #+#             */
/*   Updated: 2024/05/15 10:05:49 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	*overseer_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_if_philo_is_dead(table))
			break ;
		if (check_meals(table))
			break ;
	}
	return (NULL);
}

bool	check_meals(t_table *table)
{
	int	i;
	int	philo_full;

	i = 0;
	philo_full = 0;
	if (table->must_eat == -1)
		return (false);
	while (i < table->nb_of_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_lock);
		if (table->philos[i]->meals_eaten >= table->must_eat)
			philo_full++;
		pthread_mutex_unlock(&table->philos[i]->meal_lock);
		i++;
	}
	if (philo_full == table->nb_of_philos)
	{
		pthread_mutex_lock(&table->death_lock);
		table->death = true;
		pthread_mutex_unlock(&table->death_lock);
		return (true);
	}
	return (false);
}

bool	check_if_philo_is_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philos)
	{
		if (is_philo_dead(table->philos[i]))
		{
			display_state(I_DEATH, table->philos[i]);
			pthread_mutex_lock(&table->death_lock);
			table->death = true;
			pthread_mutex_unlock(&table->death_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if ((start_time() - philo->last_meal) > philo->table->time_to_die
		&& philo->is_eating == false)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (false);
}

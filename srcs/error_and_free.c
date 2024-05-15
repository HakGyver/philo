/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:58:25 by jteste            #+#    #+#             */
/*   Updated: 2024/05/15 11:03:21 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

bool	error_exit(char *str_error, t_table *table)
{
	ft_free_all(table);
	if (str_error)
	{
		(void)!write(2, "Error : ", 8);
		(void)!write(2, str_error, ft_strlen(str_error));
		(void)!write(2, "\n", 1);
	}
	return (true);
}

void	ft_free_all(t_table *table)
{
	int	i;

	i = 0;
	if (table->philos)
	{
		while (i < table->nb_of_philos)
		{
			if (table->philos[i])
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->write_lock);
	while (i < table->nb_of_philos)
	{
		if (table->philos[i]->is_fork_init)
			pthread_mutex_destroy(&table->philos[i]->fork);
		if (table->philos[i]->is_meal_lock_init)
			pthread_mutex_destroy(&table->philos[i]->meal_lock);
		i++;
	}
}

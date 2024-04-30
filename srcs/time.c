/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:00:51 by jteste            #+#    #+#             */
/*   Updated: 2024/04/30 12:35:55 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

time_t	start_time(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		write(2, GTOD, ft_strlen(GTOD));
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

time_t	elapsed_time(time_t start)
{
	time_t	current;

	current = start_time() - start;
	return (current);
}

void	better_usleep(time_t milliseconds)
{
	time_t	start;

	start = start_time();
	while ((start_time() - start) < milliseconds)
	{
		if (usleep(500) == -1)
			write(2, USLEEP, ft_strlen(USLEEP));
	}
}

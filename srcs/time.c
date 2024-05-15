/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:00:51 by jteste            #+#    #+#             */
/*   Updated: 2024/05/15 11:48:54 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

time_t	start_time(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		(void)!write(2, GTOD, ft_strlen(GTOD));
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	better_usleep(time_t milliseconds)
{
	time_t	microseconds;

	microseconds = milliseconds * 1000;
	if (usleep(microseconds) == -1)
		(void)!write(2, USLEEP, ft_strlen(USLEEP));
}

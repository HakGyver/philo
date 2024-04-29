/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:00:51 by jteste            #+#    #+#             */
/*   Updated: 2024/04/29 12:05:46 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

time_t	start_time(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		write(2, "Error with gettimeofday", 23);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

time_t	elapsed_time(time_t start)
{
	time_t	current;

	current = start_time() - start;
	return (current);
}

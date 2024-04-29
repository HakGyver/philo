/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:00:51 by jteste            #+#    #+#             */
/*   Updated: 2024/04/29 11:01:07 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

size_t	start_time(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		write(2, "Error with gettimeofday", 23);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

size_t	elapsed_time(size_t start)
{
	size_t	current;

	current = start_time() - start;
	return (current);
}

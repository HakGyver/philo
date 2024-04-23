/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:53:59 by jteste            #+#    #+#             */
/*   Updated: 2024/04/23 16:19:54 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			resultat;
	int			signe;

	i = 0;
	resultat = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * signe);
}

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

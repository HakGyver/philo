/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:53:59 by jteste            #+#    #+#             */
/*   Updated: 2024/05/06 14:48:01 by jteste           ###   ########.fr       */
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

bool	all_num(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
		i++;
	}
	return (false);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	display_state(int state, t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->table->write_lock);
	time = elapsed_time(philo->table->start_time);
	if (!death_check(philo))
	{
		if (state == I_SLEEP)
			printf("%s[%lums]%s %s%d%s %s%s\n", B_WHITE, time, RESET,
				B_GREEN, philo->id, B_CYAN, SLEEP, RESET);
		else if (state == I_THINK)
			printf("%s[%lums]%s %s%d%s %s%s\n", B_WHITE, time, RESET,
				B_GREEN, philo->id, B_MAGENTA, THINK, RESET);
		else if (state == I_EAT)
			printf("%s[%lums]%s %s%d%s %s%s\n", B_WHITE, time, RESET,
				B_GREEN, philo->id, B_YELLOW, EAT, RESET);
		else if (state == I_FORK)
			printf("%s[%lums]%s %s%d%s %s%s\n", B_WHITE, time, RESET,
				B_GREEN, philo->id, B_WHITE, FORK, RESET);
		else if (state == I_DEATH)
			printf("%s[%lums]%s %s%d%s %s%s\n", B_WHITE, time, RESET,
				B_GREEN, philo->id, B_RED, DEATH, RESET);
	}
	pthread_mutex_unlock(&philo->table->write_lock);
}

bool	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_lock);
	if (philo->table->death)
	{
		pthread_mutex_unlock(&philo->table->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->death_lock);
	return (false);
}

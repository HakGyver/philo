/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:53:59 by jteste            #+#    #+#             */
/*   Updated: 2024/04/22 11:55:01 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

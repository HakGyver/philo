/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:58:25 by jteste            #+#    #+#             */
/*   Updated: 2024/04/29 11:14:25 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	error_exit(char *str_error, t_table *table)
{
	ft_free_all(table);
	if (str_error)
	{
		write(2, "Error : ", 8);
		write(2, str_error, ft_strlen(str_error));
		write(2, "\n", 1);
	}
	return (EXIT_FAILURE);
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

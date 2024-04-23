/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:40:40 by jteste            #+#    #+#             */
/*   Updated: 2024/04/23 16:38:31 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	base_init(t_table *table, char const **argv)
{
	table->nb_of_philos = ft_atoi(argv[1]);
	table->start_time = start_time();
}

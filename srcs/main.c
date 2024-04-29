/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:58 by jteste            #+#    #+#             */
/*   Updated: 2024/04/29 12:36:15 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc < 5 || argc > 6)
		return (error_exit(ARG_COUNT, &table));
	if (check_args(argv, &table))
		return (EXIT_FAILURE);
	if (table_init(argv, &table))
		return (EXIT_FAILURE);
	sleep(1);
	printf("%sTime since launch :%s %lu ms\n%s",YELLOW, GREEN, elapsed_time(table.start_time), RESET);
	printf("%sNb of philos : %s%d%s\n",YELLOW,GREEN,table.nb_of_philos,RESET);
	printf("%sTime for philo to die : %s%lu ms\n%s",YELLOW,GREEN,table.time_to_die,RESET);
	printf("%sTime for philo to eat : %s%lu ms\n%s" ,YELLOW,GREEN, table.time_to_eat,RESET);
	printf("%sTime for philo to sleep : %s%lu ms\n%s",YELLOW,GREEN, table.time_to_sleep,RESET);
	printf("%sNb of meals philos must eat: %s%d\n%s",YELLOW,GREEN,table.must_eat,RESET);
	printf("%sDeath flag: %s%d\n%s",YELLOW,GREEN,table.death,RESET);
	pthread_mutex_destroy(&table.death_lock);
	pthread_mutex_destroy(&table.write_lock);
	ft_free_all(&table);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:58 by jteste            #+#    #+#             */
/*   Updated: 2024/04/30 12:35:36 by jteste           ###   ########.fr       */
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
	if (philo_init(&table))
		return (EXIT_FAILURE);
	printf("\n-----------------TABLE-----------------------\n\n");
	printf("%sNb of philos : %s%d%s\n",YELLOW,GREEN,table.nb_of_philos,RESET);
	printf("%sTime for philo to die : %s%lu ms\n%s",YELLOW,GREEN,table.time_to_die,RESET);
	printf("%sTime for philo to eat : %s%lu ms\n%s" ,YELLOW,GREEN, table.time_to_eat,RESET);
	printf("%sTime for philo to sleep : %s%lu ms\n%s",YELLOW,GREEN, table.time_to_sleep,RESET);
	printf("%sNb of meals philos must eat: %s%d\n%s",YELLOW,GREEN,table.must_eat,RESET);
	printf("%sDeath flag: %s%d\n%s",YELLOW,GREEN,table.death,RESET);
	printf("%sTable adress :%s%s%p%s\n",YELLOW,RESET,GREEN,&table,RESET);
	for(int i = 0; i < table.nb_of_philos; i++)
	{
		printf("\n------------------PHILO[%s%d%s]-----------------------\n\n",YELLOW,table.philos[i]->id,RESET);
		if(i == 0)
			printf("%sTable adress :%s%s%p%s\n",YELLOW,RESET,GREEN,table.philos[i]->table,RESET);
		printf("%sLast meal :%s %s%lu%s\n",YELLOW,RESET,GREEN,table.philos[i]->last_meal,RESET);
		printf("%sTime since last meal :%s %s%lu ms%s\n",YELLOW,RESET,GREEN,elapsed_time(table.philos[i]->last_meal),RESET);
		printf("%sMeals eaten :%s %s%d%s\n",YELLOW,RESET,GREEN, table.philos[i]->meals_eaten,RESET);
		printf("%sOwn fork adress :%s %s%p%s\n",YELLOW,RESET,GREEN,&table.philos[i]->fork,RESET);
		printf("%sLeft fork adress :%s %s%p%s\n",YELLOW,RESET,GREEN,table.philos[i]->fork_left,RESET);
		better_usleep(500);
	}
	destroy_mutex(&table);
	ft_free_all(&table);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:58 by jteste            #+#    #+#             */
/*   Updated: 2024/04/25 17:00:31 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of arguments\n", 25), EXIT_FAILURE);
	if (check_args(argv) == false)
		return (EXIT_FAILURE);
	table_init(&table, argv);
	while (1)
		printf("all good rn, %lu since launch\n", elapsed_time(table.start_time));
	return (0);
}

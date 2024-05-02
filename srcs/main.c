/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:58 by jteste            #+#    #+#             */
/*   Updated: 2024/05/02 13:21:04 by jteste           ###   ########.fr       */
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
	if (threads_creation(&table))
		return (EXIT_FAILURE);
	if (threads_join(&table))
		return (EXIT_FAILURE);
	destroy_mutex(&table);
	ft_free_all(&table);
	return (EXIT_SUCCESS);
}

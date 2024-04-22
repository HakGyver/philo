/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:58 by jteste            #+#    #+#             */
/*   Updated: 2024/04/22 12:57:12 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_num(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	check_args(char const **argv)
{
	if (ft_atoi(argv[1]) <= 0 || all_num(argv[1]) == false)
		return (write(2, "Wrong number of philosophers\n", 29), false);
	if (ft_atoi(argv[2]) <= 0 || all_num(argv[2]) == false)
		return (write(2, "Wrong time to die\n", 18), false);
	if (ft_atoi(argv[3]) <= 0 || all_num(argv[3]) == false)
		return (write(2, "Wrong time to eat\n", 18), false);
	if (ft_atoi(argv[4]) <= 0 || all_num(argv[4]) == false)
		return (write(2, "Wrong time to sleep\n", 20), false);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || all_num(argv[5]) == false))
		return (write(2, "Wrong number of times philosophers must eat\n", 44),
			false);
	return (true);
}

int	main(int argc, char const *argv[])
{
	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of argument\n", 25), EXIT_FAILURE);
	if (check_args(argv) == false)
		return (EXIT_FAILURE);
	printf("all good");
	return (0);
}

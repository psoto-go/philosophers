/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:12:39 by psoto-go          #+#    #+#             */
/*   Updated: 2023/01/24 19:32:04 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_values(t_inputs *philo, int argc)
{
	philo->num_philos = 0;
	philo->num_forks = 0;
	philo->time_to_die = 0;
	philo->time_to_sleep = 0;
	philo->time_to_eat = 0;
	if (argc == 6)
		philo->num_times_must_eat = 0;
	else if (argc < 6)
		philo->num_times_must_eat = -1;
	philo->everyone_alive = 0;
}

void	check_num_args(int argc)
{
	if (argc < 5 || argc > 6)
		ft_error(1);
}

void	check_corrects_inputs(t_inputs *philo, char **argv)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				ft_error(2);
			j++;
		}
		if (ft_atol(argv[i], &flag) && flag == 1)
			ft_error(3);
		i++;
	}
	philo = 0;
}

void	fill_struct(t_inputs *philo, char **argv)
{
	int 	flag;
	struct 	timeval time;

	flag = 0;
	philo->num_philos = ft_atoi(argv[1], &flag);
	philo->num_forks = ft_atoi(argv[1], &flag);
	philo->time_to_die = ft_atoi(argv[2], &flag);
	philo->time_to_eat = ft_atoi(argv[3], &flag);
	philo->time_to_sleep = ft_atoi(argv[4], &flag);
	if (argv[5])
		philo->num_times_must_eat = ft_atoi(argv[5], &flag);
	gettimeofday(&time, NULL);
	philo->time_start = time;
}

void	check_inputs(int argc, char **argv, t_inputs *philo)
{
	check_num_args(argc);
	init_values(philo, argc);
	check_corrects_inputs(philo, argv);
	fill_struct(philo, argv);
	printf("%lld\n", philo->num_philos);
	printf("%lld\n", philo->num_forks);
	printf("%lld\n", philo->time_to_die);
	printf("%lld\n", philo->time_to_eat);
	printf("%lld\n", philo->time_to_sleep);
	if (philo->num_times_must_eat)
		printf("%lld\n", philo->num_times_must_eat);
	printf("%d alive\n", philo->everyone_alive);
	// printf("%d time\n", philo->time_start);
}
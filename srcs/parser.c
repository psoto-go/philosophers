/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:12:39 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/04 16:31:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_values(t_philo *philo, int argc)
{
	philo->num_philos = 0;
	philo->num_forks = 0;
	philo->time_to_die = 0;
	philo->time_to_sleep = 0;
	philo->time_to_eat = 0;
	if (argc == 6)
		philo->num_times_must_eat = 0;
}

void	check_num_args(int argc)
{
	if (argc < 5 || argc > 6)
		ft_error(1);
}

void	check_corrects_inputs(t_philo *philo, char **argv)
{
	int i;
	int	j;

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
		i++;
	}
	philo = 0;
}

void	fill_struct(t_philo *philo, char **argv)
{
	philo->num_philos = ft_atol(argv[1]);
	philo->num_forks = ft_atol(argv[1]);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->num_times_must_eat = ft_atol(argv[5]);
}


void	check_inputs(int argc, char **argv, t_philo *philo)
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
	printf("%lld\n", philo->num_times_must_eat);
}
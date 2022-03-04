/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:51:50 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/04 16:32:40 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

typedef struct philo
{
	long long	num_philos;
	long long	num_forks;
	long long	time_to_die;
	long long	time_to_sleep;
	long long	time_to_eat;
	long long	num_times_must_eat;
} t_philo;

void	check_inputs(int argc, char **argv, t_philo *philo);

void	ft_error(int num);


// Utils

int		ft_isdigit(int c);
long		ft_atol(const char *str);

#endif
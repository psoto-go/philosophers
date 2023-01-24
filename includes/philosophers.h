/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:51:50 by psoto-go          #+#    #+#             */
/*   Updated: 2023/01/24 20:25:11 by psoto-go         ###   ########.fr       */
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
# include <pthread.h>
# include <sys/time.h>

struct s_inputs;

typedef struct s_philosopher
{
	long long		num_philo;
	long long		eaten;
	long long		its_alive;
	struct timeval	last_eat;
	struct timeval	last_sleep;
	struct timeval	time;
	pthread_t		pid;
	struct s_inputs	*inputs;
} t_philosopher;

typedef struct s_inputs
{
	long long		num_philos;
	long long		num_forks;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		time_to_eat;
	long long		num_times_must_eat;
	struct timeval	time_start;
	int				everyone_alive;
	t_philosopher	**philosophers;

} t_inputs;

void			check_inputs(int argc, char **argv, t_inputs *philo);

void			ft_error(int num);

t_philosopher	*new_philo(t_inputs *philo, int philo_index);

int				fill_philos(t_inputs *philo);


// Utils

int			ft_isdigit(int c);
long		ft_atol(const char *str, int *flag);
int			ft_atoi(const char *str, int *flag);

#endif
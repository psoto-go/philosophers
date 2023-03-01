/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:51:50 by psoto-go          #+#    #+#             */
/*   Updated: 2023/03/01 20:03:43 by psoto-go         ###   ########.fr       */
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
# include <stdbool.h>

struct s_inputs;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING
} 			t_state;

typedef struct s_philosopher
{
	long long		num_philo;
	long long		eaten;
	bool			its_alive;
	struct timeval	last_eat;
	struct timeval	last_sleep;
	struct timeval	time;
	pthread_t		pid;
	t_state			state;
	struct s_inputs	*inputs;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

} t_philosopher;

typedef struct s_inputs
{
	long long		num_philos;
	long long		num_forks;
	pthread_mutex_t	*forks;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		time_to_eat;
	long long		num_times_must_eat;
	struct timeval	time_start;
	int				everyone_alive;
	bool			end;
	t_philosopher	**philosophers;

} t_inputs;

void			check_inputs(int argc, char **argv, t_inputs *philo);

void			ft_error(int num);

t_philosopher	*new_philo(t_inputs *philo, int philo_index);

int				fill_philos(t_inputs *philo);

void			*starting(void *argc);
// Utils

int			ft_isdigit(int c);
long		ft_atol(const char *str, int *flag);
int			ft_atoi(const char *str, int *flag);

#endif
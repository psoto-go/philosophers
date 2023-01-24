/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:19:26 by psoto-go          #+#    #+#             */
/*   Updated: 2023/01/24 20:35:02 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher *new_philo(t_inputs *philos, int philo_index)
{
    t_philosopher   *philo;

    philo = (t_philosopher *)malloc(sizeof(t_philosopher));
    if (!philo)
        ft_error(4);
    philo->num_philo	= philo_index;
    philo->last_eat		= philo->time;
    philo->eaten		= 0;
    philo->its_alive	= 1;
	philo->inputs		= philos;
    return(philo);
}

int	fill_philos(t_inputs *philos)
{
    int i;

    i = 0;
    philos->philosophers = (t_philosopher **)malloc(sizeof(t_philosopher *) * philos->num_philos);
    if (!philos->philosophers)
        ft_error(4);
    while (i < philos->num_philos)
    {
        philos->philosophers[i] = new_philo(philos, i);
        if (!philos->philosophers[i])
            ft_error(5);
        i++;
    }
	i = 0;
	while (i < philos->num_philos)
    {
        // pthread_create(&philos->philosophers[i]->pid, NULL,)
        i++;
    }

    return(i);
}
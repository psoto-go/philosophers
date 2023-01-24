/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:15:53 by psoto-go          #+#    #+#             */
/*   Updated: 2023/01/24 19:55:49 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_exit(void)
{
	exit(0);
}

void	ft_error(int num)
{
	if (num == 1)
		printf("%s\n", "Numero de argumentos incorrecto");
	if (num == 2)
		printf("%s\n", "Error de argumentos");
	if (num == 3)
		printf("%s\n", "Numero mas largo de int");
	if (num == 4)
		printf("%s\n", "Error alocando memoria");
	if (num == 5)
		printf("%s\n", "Error creando filosofo");
	ft_exit();
}

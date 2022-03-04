/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:27:47 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/04 16:32:35 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ignorespaces(const char *str)
{
	int	spaces;

	spaces = 0;
	while (str[spaces] == ' ' || str[spaces] == '\t' || str[spaces] == '\n' || \
	str[spaces] == '\r' || str[spaces] == '\v' || str[spaces] == '\f')
		spaces++;
	return (spaces);
}

long	ft_atol(const char *str)
{
	char		*text;
	int			spaces;
	long long	sig;
	long long	res;

	text = (char *)str;
	sig = 1;
	res = 0;
	spaces = ignorespaces(str);
	if (str[spaces] == '-')
		sig = -1;
	if (str[spaces] == '-' || str[spaces] == '+')
		spaces++;
	while (str[spaces] >= '0' && str[spaces] <= '9')
	{
		res = res * 10 + (str[spaces] - '0');
		spaces++;
		if (res * sig > 9223372036854775807)
			ft_error(3);
		if (res * sig < -9223372036854775807)
			ft_error(3);
	}
	res = res * sig;
	return ((long)res);
}
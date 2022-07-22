/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:44 by htomas-d          #+#    #+#             */
/*   Updated: 2022/07/22 14:18:10 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	*invert(int c)
{
	int	*array;
	int	i;

	i = 7;
	array = malloc(sizeof(int) * 8);
	while ((c) != 0)
	{
		array[i] = c % 2;
		c /= 2;
		i--;
	}
	while (i >= 0)
		array[i--] = 0;
	return (array);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}

void	sendsignal(int *array, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (array[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	free(array);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minuscount;
	int	nb;

	i = 0;
	nb = 0;
	minuscount = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minuscount = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * minuscount);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	input;

	if (argc != 3)
	{
		ft_printf("\e[0;31mWRONG NUMBER OF ARGUMENTS:\n");
		ft_printf("\e[0;32m./client [SERVER PID] [STRING]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		input = ft_isprint((int)(argv[2][i]));
		sendsignal(invert(input), pid);
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

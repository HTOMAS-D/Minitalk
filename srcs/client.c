/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:44 by htomas-d          #+#    #+#             */
/*   Updated: 2022/06/02 15:19:24 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>

int	*invert(int c)
{
	int	*array;
	int	i;

	i = 7;
	array = malloc(sizeof(int) * 8);
	while((c) != 0)
	{
		array[i] = c % 2;
		c /= 2;
		i--;
	}
	while(i > 0)
		array[i--] = 0;
	return (array);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

void	sendsignal(int *array, int pid)
{
	int i;

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

int ft_atoi(const char *str)
{
	int	i;
	int	minuscount;
	int	nb;

	i = 0;
	nb = 0;
	minuscount = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
	if (str[i] == '-')
	{
		minuscount = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] -'0');
		i++;
	}
	return (nb * minuscount);
}

int main(int argc, char **argv)
{
//	(void)argc;
//	(void) argv;
	int	pid;
	int	i;
	int	input;

	if(argc != 3)
	{
		ft_printf("\e[0;31mWRONG NUMBER OF ARGUMENTS:\n\e[0;32m./client [INPUT SERVER PID] [STRING]\n");
		return 0;
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		input = ft_isprint((int) (argv[2][i]));
		sendsignal(invert(input), pid);
		i++;
	}
	i = 0;
	while(i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

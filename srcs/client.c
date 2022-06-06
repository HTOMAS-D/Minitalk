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

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126)
}

void	sendsignal(int *array, int pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (array[i] = 0)
		{
			kill(pid, SIGUSR1);
		}
		else if (array[i] = 1)
		{
			kill(pid, SIGUSR2);
		}
		i++;
	}
	free(array);
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

	}
}

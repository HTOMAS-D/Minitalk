/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:52 by htomas-d          #+#    #+#             */
/*   Updated: 2022/06/02 15:19:21 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>

int	g = 0;

void	get_string(int signal)
{
	char str[9];
	
	if (signal == 30)
		str[g++] = '0';
	else if (signal == 31)
		str[g++] = '1';
	if (g == 8)
	{
		str[g] = '\0';
		g = 0;
	}
}

int main()
{
	ft_printf("\e[0;32mSERVER PID: %d\n", getpid());
	signal(SIGUSR1, get_string);
	signal(SIGUSR2, get_string);
	while(1)
		;
}

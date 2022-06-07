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
#include <stdlib.h>
#include <stdio.h>


int	g = 0;

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return 0;
	else if (power == 0)
		return 1;
	else
		return (nb * ft_recursive_power(power, power - 1));
}

int	backtoint(unsigned char	*str)
{
	int	a;
	int	result;

	a = 7;
	result = 0;
	while(a >= 0)
	{
		if (str[a] == '1')
			result += 1 * ft_recursive_power(2, (7 - a));
		a--;
	}
	return (result);
}

void	get_string(int signal)
{
	unsigned char	str[9];
	int	strdone;

	if (signal == 30)
		str[g++] = '0';
	else if (signal == 31)
		str[g++] = '1';
	if (g == 8)
	{	
		str[g] = '\0';
		if(str[0] == '1')
		{
			g = write(1, "\n", 1) - 1;
			return;
		}
//		printf("%s", str);
		strdone = backtoint(str);
		ft_printf("%c", strdone);
		g = 0;
	}
}

int main(void)
{
	ft_printf("\e[0;32mSERVER PID: %d\n", getpid());
	signal(SIGUSR1, get_string);
	signal(SIGUSR2, get_string);
	while(1)
		;
}

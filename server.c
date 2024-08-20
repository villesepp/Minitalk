/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/08/19 16:55:11 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for getpid 
#include <unistd.h>

#include <stdio.h> // delete deb
#include <signal.h>

static int bit_shiftleft_and (int num)
{
	num = num << 1;
	num = num & 1;
	return (num);
}


static void	signal_usr(int signum) 
{
	static int	bit = 0;
	static int	value = 0;

	if (signal == SIGUSR1)
		value = bit_shiftleft_and(value, 0);
	else
		value = bit_shiftleft_and(value, 1);
	bit++;
	if (bit == 8)
	{
		ft_putchar(value);
		bit = 0;
		value = 0;
	}
}

void signal_usr1(int signum) 
{

}


int main (void)
{
	printf("Server pid is %d, waiting for signals...\n", getpid());

	while(1)
	{
		signal(SIGUSR1, signal_usr);
		signal(SIGUSR2, signal_usr);
		pause();
	}

	return (0);
}

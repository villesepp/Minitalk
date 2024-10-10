/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 15:24:18 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack;

/*
 *	- receive 'acknowledge' signal and switch the global variable
 *	- exit the client
 */
static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		(void) signal;
		g_ack = 1;
	}
	if (signal == SIGUSR2)
		exit (EXIT_SUCCESS);
}

/*
 *	- send signal based on the bit of c
 *	- wait for signal from server or else stop and exit
 */
static void	char_send(int c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c << bit & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (!g_ack)
		{
			sleep(TIMEOUT_LIMIT);
			if (!g_ack)
			{
				ft_putendl_fd("Server stopped responding\n", 2);
				exit (EXIT_FAILURE);
			}
		}
		g_ack = 0;
	}
}

/*
 *	- get the PID from the argument
 *	- pass each character individually to other function
 *	- send \0
 */
static void	string_send(char **argv)
{
	int	i;
	int	pid;

	ft_putstr_fd("Sending a string with character count: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putendl_fd("\n", 1);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		char_send(argv[2][i], pid);
		i++;
	}
	char_send(0, pid);
}

/*
 *	- check if PID consists of only digits
 *	- check if PID is within valid range on 64-bit systems
 */
static int	pid_check(char *str)
{
	int	pid;
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	pid = ft_atoi(str);
	if (pid < 1 || pid > 4194304)
		return (1);
	return (0);
}

/*
 * - check args
 * - initialize signals
 */
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || pid_check(argv[1]) || ft_strlen(argv[2]) > 2097140)
	{
		ft_putendl_fd("Usage: ./client SERVER_PID 'string to transmit'", 2);
		exit (EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	string_send(argv);
	return (0);
}

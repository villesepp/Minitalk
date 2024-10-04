/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/08/19 16:59:04 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *	- send signal based on the bit of c
 *	- sleep for a moment after each signal to lessen the chance of errors
 */
static void	char_send_pid(int c, int pid)
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
		usleep(600);
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

	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		char_send_pid(argv[2][i], pid);
		i++;
	}
	char_send_pid(0, pid);
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
 * - check if argument count is exactly 3
 * - call PID check function
 * - check if string argument is not bigger than (ARG_MAX - client - PID) bytes long
 */
static int	check_args(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (pid_check(argv[1]))
		return (1);
	if (ft_strlen(argv[2]) > 2097140)
		return (1);
	return (0);
}

int main (int argc, char **argv)
{
	if (check_args(argc, argv))
		return (-1);
    string_send(argv);
	return (0);
}

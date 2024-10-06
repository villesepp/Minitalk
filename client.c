/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/06 14:11:11 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *	- wait for the signal to continue
 */
static void signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_putendl_fd("CL: ack received", 1);
}

/*
 *	- send signal based on the bit of c
 *	- sleep for a moment after each signal to lessen the chance of errors
 */
static void	char_send(int c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		printf("C bit send\n");
		if (c << bit & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		// usleep(100);
		printf("C going to pause\n");
		pause();
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

	printf("C string send\n");
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		char_send(argv[2][i], pid);
		i++;
	}
	printf("C zero/null send\n");
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

	printf("C pid check\n");
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
 * - check if string argument is not over (ARG_MAX - client - PID) bytes long
 */
static void	args_check(int argc, char **argv)
{
	printf("C args check\n");
	if (argc != 3 || pid_check(argv[1]) || ft_strlen(argv[2]) > 2097140)
		exit (EXIT_FAILURE);
	
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	args_check(argc, argv);

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler;
	sigaction (SIGUSR1, &sa, NULL);

	printf("C client pid: %d\n", getpid());
	string_send(argv);
	return (0);
}

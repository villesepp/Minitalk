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


#include <stdio.h> // delete deb
#include <math.h> // delete deb
#include <stdlib.h> // for atoi so delete deb


#include <sys/types.h> // for pid, kill
#include <signal.h> // for pid, kill


static void	char_send(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
		i++;
	}
}

static void	string_send(char **argv)
{
	int	i;

	i = 0;
	while (argv[2][i])
		char_send(argv[i]);
}

static int	check_args(int argc, char **argv)
{
	int 	pid;

	if (argc != 3)
	{
		if (argc == 2)
			printf("\033[31mError: Missing string to send\033[0m\n"); // use putendl, with stderror
		else if (argc > 3)
			printf("\033[31mError: Too many arguments\033[0m\n");
		printf("Usage: pid_number \"string to send\"\n");
		return (1);
	}
	pid = atoi(argv[1]);	// deb use ft_atoi
	if (pid < 1 || pid > 4194304)
	{
		printf("Invalid process id\n"); // use puetndl with stderror
		return (1);
	}
	if (strlen(argv[1]) > 4000) // over some max len.. check
		return (1);
	return (0);
}


int main (int argc, char **argv)
{
	int	pid;

	if (check_args(argc, argv))
		return (-1);
	pid = atoi(argv[1]);

    string_send(argv[2]);

	//temp delete
	/*
	int custom = atoi(argv[2]);
	int result = 0;

	if (custom == 2)
		result = kill(pid, SIGUSR2);
	else
		result = kill(pid, SIGUSR1);

    if (result == 0)
		printf("Success.\n");
	else
		printf("Fail.\n");
	*/

	return (0);
}

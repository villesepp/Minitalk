/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/08/19 16:48:23 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> // delete deb
#include <math.h> // delete deb
#include <stdlib.h> // for atoi so delete deb


#include <sys/types.h> // for pid, kill
#include <signal.h> // for pid, kill


int	check_args(int argc, char **argv)
{
	int 	pid;

	if (argc != 3)
	{
		if (argc == 2)
			printf("\033[31mError: Missing string to send\033[0m\n");
		else if (argc > 3)
			printf("\033[31mError: Too many arguments\033[0m\n");
		printf("Usage: pid_number \"string to send\"\n");
		return (1);
	}
	pid = atoi(argv[1]);	// deb use ft_atoi
	if (pid < 1 || pid > 4194304)
	{
		printf("Invalid process id\n");
		return (1);
	}
	return (0);
}


int main (int argc, char **argv)
{
	int	pid;

	if (check_args(argc, argv))
		return (0);
	pid = atoi(argv[1]);

    int result = kill(pid, SIGINT);

    if (result == 0)
		printf("Success.\n");
	else
		printf("Fail.\n");
	return (0);
}

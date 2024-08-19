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

void signalHandler(int signalNumber) 
{
    printf("Received signal for 1: %d\n", signalNumber);
}


void signalHandler2(int signalNumber) 
{
    printf("Received signal for 2: %d\n", signalNumber);
}

int main (void)
{
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler2);
	printf("Server pid is %d\n", getpid());

	while(1) ;

	return (0);
}

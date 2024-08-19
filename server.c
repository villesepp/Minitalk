/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:27:05 by vseppane          #+#    #+#             */
/*   Updated: 2024/08/19 16:48:16 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for getpid 
#include <unistd.h>

#include <stdio.h> // delete deb
#include <signal.h>

void signalHandler(int signalNumber) 
{
    printf("Received signal: %d\n", signalNumber);
    /* Perform actions or tasks based on the signal received */
}

int main (void)
{
	signal(SIGINT, signalHandler);
	printf("Server pid is %d\n", getpid());

	while(1) ;

	return (0);
}

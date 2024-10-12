/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:22:11 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 15:40:32 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_client(int pid, int signal)
{
	if (signal == 0)
		kill(pid, SIGUSR1);
	if (signal == 1)
		kill(pid, SIGUSR2);
}

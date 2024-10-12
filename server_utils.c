/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:01:15 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/12 12:01:25 by vseppane         ###   ########.fr       */
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

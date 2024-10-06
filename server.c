/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:37:12 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/06 17:54:58 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * - send acknowledgement of signal received
 */
static void	ack_send(int pid, int signal)
{
	if (signal == 0)
		kill(pid, SIGUSR1);
	if (signal == 1)
		kill(pid, SIGUSR2);
}

static char	*char_append(char *str, char c)
{
	char		*new;
	int			len;

	len = ft_strlen(str);
	new = malloc(len + 2);
	if (new == NULL)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new, str, len);
	new[len] = c;
	new[len + 1] = '\0';
	free (str);
	return (new);
}

static unsigned char	bit_append(int signal, unsigned char c)
{
	if (signal == SIGUSR2)
		c = c << 1;
	else
		c = (c << 1) | 1;
	return (c);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				bits = 0;
	static unsigned char	c = 0;
	static char				*str;
	int						client_pid;

	usleep(SLEEPTIME);
	(void)context;
	client_pid = info->si_pid;
	if (str == NULL)
	{
		str = ft_strdup("");
		if (str == NULL)
			exit(EXIT_FAILURE);
	}
	c = bit_append(signal, c);
	bits++;
	if (bits == 8)
	{
		str = char_append(str, c);
		if (c == '\0')
		{
			write(1, str, ft_strlen(str));
			free (str);
			str = NULL;
			ack_send(client_pid, 1);
		}
		bits = 0;
		c = 0;
	}
	ack_send(client_pid, 0);
}

int	main(void)
{
	struct sigaction	sa;
	int					signal_received;

	ft_putstr_fd("Server process id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	signal_received = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

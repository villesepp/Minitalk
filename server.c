/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:37:12 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/06 14:14:21 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * - send acknowledgement of signal received
 */
static void ack_send(int pid)
{
	printf("SRV send ack to client pid: %d\n", pid);
	kill(pid, SIGUSR1);
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
	free((void*)str);
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

	printf("SRV signal handler\n");
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
	ack_send(client_pid);
	if (bits == 8)
	{
		str = char_append(str, c);
		if (c == '\0')
		{
			write(1, str, ft_strlen(str));
			free (str);
			str = NULL;
		}
		bits = 0;
		c = 0;
	}
}

static void args_check(int argc, char **argv)
{
	(void) argv;
	if (argc != 1)
		exit(EXIT_FAILURE);
	ft_putstr_fd("Server process id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	args_check(argc, argv);

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("SRV after sigaction\n");
	while (1)
	{
		pause();
	}
	return (0);
}

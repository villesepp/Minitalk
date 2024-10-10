/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:37:12 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 15:23:39 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * - malloc and add a new char to str
 */
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

/*
 * - shift bit to left and use '1' mask if SIGUSR1
 */
static unsigned char	bit_append(int signal, unsigned char c)
{
	if (signal == SIGUSR2)
		c = c << 1;
	else
		c = (c << 1) | 1;
	return (c);
}

/*
 * - add c to string
 * - print, free string if done
 * - send ack
 * - reset bit count and c
 */
void	char_process(unsigned char *c, int *bits, int *client_pid, char **str)
{
	*str = char_append(*str, *c);
	if (*c == '\0')
	{
		ft_putstr_fd(*str, 1);
		ft_putstr_fd("\nMessage received lenght was: ", 1);
		ft_putnbr_fd(ft_strlen(*str), 1);
		ft_putendl_fd("", 1);
		free(*str);
		*str = NULL;
		ack_send(*client_pid, 1);
	}
	*bits = 0;
	*c = 0;
}

/*
 * - initialize string if necessary
 * - append bit to c
 */
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				bits = 0;
	static unsigned char	c = 0;
	static char				*str;
	int						client_pid;

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
		char_process(&c, &bits, &client_pid, &str);
	ack_send(client_pid, 0);
}

/*
 * - print server ID
 * - initialize signals
 * - pause in a loop to wait for signals
 */
int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server process id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

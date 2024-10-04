
#include "minitalk.h"

static char	*char_append(char *str, char c)
{
	char	*new;
	size_t		len;

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
	free(str);
	return (new);
}

static unsigned char	bit_append(int signal, unsigned char c)
{
	if (signal == SIGUSR2)
		c = c << 1;
	else if (signal == SIGUSR1)
		c = (c << 1) | 1;
	return (c);
}


static void	signal_handler(int signal)
{
	static int				bits = 0;
	static char				*str;
	static unsigned char	c = 0;

	c = bit_append(signal, c);

	bits++;
	if (bits == 8)
	{
		if (str == NULL)
			str = ft_strdup("");
		if (str == NULL)
    	    exit(EXIT_FAILURE);
		
		str = char_append(str, c);
		if (c == '\0')
		{
			ft_putstr_fd(str, 1);
			free (str);
			str = NULL;
		}
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server process id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}

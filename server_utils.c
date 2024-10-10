#include "minitalk.h"

void	signal_client(int pid, int signal)
{
	if (signal == 0)
		kill(pid, SIGUSR1);
	if (signal == 1)
		kill(pid, SIGUSR2);
}

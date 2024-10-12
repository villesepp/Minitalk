/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:22:11 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 15:40:32 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TIMEOUT_LIMIT 10

# include "libft/libft.h"
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <stdlib.h>

void    signal_client(int pid, int signal);
int		pid_check(char *str);

#endif

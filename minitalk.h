/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:22:11 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 13:53:25 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SLEEPTIME 400

# include "libft/libft.h"
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void    ack_send(int pid, int signal);

#endif

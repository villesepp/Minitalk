/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:22:11 by vseppane          #+#    #+#             */
/*   Updated: 2024/10/10 15:24:59 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TIMEOUT_LIMIT 5

# include "libft/libft.h"
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <stdlib.h>

void    ack_send(int pid, int signal);

#endif

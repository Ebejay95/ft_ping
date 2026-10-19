/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:15:29 by jeberle           #+#    #+#             */
/*   Updated: 2026/10/19 17:16:34 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	handle_sigint(int signum)
{
	(void)signum;
	g_stop = 1;
}

int	ping_cycle(t_ping *ping)
{
	prepare_step(ping);
	if (send_ping(ping) != 0)
		return (1);
	if (receive_ping(ping) != 0)
		return (1);
	ping->count++;
	ft_printf(BLUE"Ping %d to %s\n"RESET, ping->count, ping->target);
	return (0);
}

int	ping_loop(t_ping *ping)
{
	signal(SIGINT, handle_sigint);
	while (true)
	{
		if (g_stop)
			break ;
		if (ping_cycle(ping) != 0)
		{
			set_error(ping, ERR_PING_FAILED, NULL);
			return (1);
		}
		if (g_stop)
			break ;
		sleep(1);
	}
	return (0);
}

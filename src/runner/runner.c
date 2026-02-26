/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:34:08 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/26 21:31:20 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static int	g_stop = 0;

int	setup_ping(t_ping *ping)
{
	// ping->socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	ping->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (ping->socket_fd < 0)
	{
		set_error(ping, ERR_SOCKET_FAILED, NULL);
		return (1);
	}
	return (0);
}

void	handle_sigint(int signum)
{
	(void)signum;
	g_stop = 1;
}

int	prepare_step(t_ping *ping)
{
	(void)ping;
	// Prepare ICMP packet here (not implemented in this snippet)
	return (0);
}

int	send_ping(t_ping *ping)
{
	(void)ping;
	// Send ICMP packet here (not implemented in this snippet)
	return (0);
}

int	receive_ping(t_ping *ping)
{
	(void)ping;
	// Receive ICMP reply here (not implemented in this snippet)
	return (0);
}

int	ping_cycle(t_ping *ping)
{
	prepare_step(ping);
	if (send_ping(ping) != 0)
		return (1);
	if (receive_ping(ping) != 0)
		return (1);
	ft_printf(BLUE"Ping %d to %s\n"RESET, ping->count + 1, ping->target);
	ping->count++;
	return (0);
}

int	ping_loop(t_ping *ping)
{
	while (true)
	{
		if (ping_cycle(ping) != 0)
		{
			set_error(ping, ERR_PING_FAILED, NULL);
			return (1);
		}
		sleep(1);
		signal(SIGINT, handle_sigint);
		if (g_stop)
			break ;
	}
	return (0);
}

int	ping_result(t_ping *ping)
{
	ft_printf(GREEN"\n\nPing to ");
	ft_printf("%s", ping->target);
	ft_printf(" completed after %d attempts\n"RESET, ping->count);
	return (0);
}

int	run_ping(t_ping *ping)
{	
	ft_printf(YELLOW"Running ping to %s\n"RESET, ping->target);
	if (setup_ping(ping) != 0)
		return (1);
	if (ping_loop(ping) != 0)
		return (1);
	if (ping_result(ping) != 0)
		return (1);
	return (0);
}

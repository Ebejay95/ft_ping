/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:34:08 by jeberle           #+#    #+#             */
/*   Updated: 2026/10/19 17:15:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static int	g_stop = 0;

int	setup_ping(t_ping *ping)
{
	ping->socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->socket_fd < 0)
	{
		set_error(ping, ERR_SOCKET_FAILED, NULL);
		return (1);
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

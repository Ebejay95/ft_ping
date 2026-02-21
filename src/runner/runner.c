/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:34:08 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 20:18:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

int	run_ping(t_ping *ping)
{	
	ft_printf(YELLOW"Running ping to %s\n"RESET, ping->target);

	socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->socket_fd < 0)
	{
		set_error(ping, ERR_SOCKET_FAILED, NULL);
		return (1);
	}
	return (0);
}

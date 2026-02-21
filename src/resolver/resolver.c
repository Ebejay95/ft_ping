/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:33:31 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 19:57:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

int	resolve_hostname(t_ping *ping)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				result;

	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	result = getaddrinfo(ping->target, NULL, &hints, &res);
	if (result != 0)
	{
		set_error(ping, ERR_INVALID_HOST, ping->target);
		return (1);
	}
	ft_memcpy(&(ping->resolved_addr), res->ai_addr, sizeof(struct sockaddr_in));
	freeaddrinfo(res);
	return (0);
}

int	resolve_target(t_ping *ping)
{
	t_sockaddr_in	sa;
	int				result;

	ft_printf("resolving %s...\n", ping->target);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	result = inet_pton(AF_INET, ping->target, &(sa.sin_addr));
	if (result == 1)
	{
		ping->resolved_addr = sa;
		return (0);
	}
	if (result == -1)
	{
		set_error(ping, ERR_INVALID_HOST, ping->target);
		return (1);
	}
	return (resolve_hostname(ping));
}

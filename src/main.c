/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:18:37 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/19 20:37:01 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	initialize_ping(t_ping *ping)
{
	ping->target = NULL;
	ping->verbose = 0;
	ping->help = 0;
	ping->error_message = NULL;
}

int	main(int argc, char **argv)
{
	t_ping	*ping;

	if (argc < 2)
	{
		ft_printf(RED"Usage: %s <hostname>\n"RESET, argv[0]);
		return (1);
	}
	if (argc >= 2)
	{
		ping = (t_ping *)malloc(sizeof(t_ping));
		if (!ping)
			return (1);
		initialize_ping(ping);
		ping = parse_arguments(ping, argc, argv);
		if (!ping->target)
			return (1);
		{
			ft_printf(RED"Error: Invalid arguments\n"RESET);
			return (1);
		}
	}
	ft_printf(CYAN"ft_ping is a work in progress!\n"RESET);
	return (0);
}

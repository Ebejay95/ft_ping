/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:18:37 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 18:28:08 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	resolve_target(t_ping *ping)
{
	(void)ping;
	ft_printf(YELLOW"Resolving target %s\n"RESET, ping->target);
}

void	run_ping(t_ping *ping)
{	
	(void)ping;
	ft_printf(YELLOW"Running ping to %s\n"RESET, ping->target);
}

int	handle_ping(t_ping	*ping)
{
	if (ping->help)
	{
		ping_help();
		clean_ping(ping);
		return (0);
	}
	resolve_target(ping);
	run_ping(ping);
	clean_ping(ping);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ping	*ping;

	if (argc < 2)
	{
		ft_printf(RED"Usage: %s <destnation>\n"RESET, argv[0]);
		return (1);
	}
	if (argc >= 2)
	{
		ping = (t_ping *)malloc(sizeof(t_ping));
		if (!ping)
			return (1);
		initialize_ping(ping);
		ping = parse_arguments(ping, argc, argv);
		if (ping->error_code != ERR_NONE)
		{
			print_error(ping, argv[0]);
			clean_ping(ping);
			return (1);
		}
		return (handle_ping(ping));
	}
	return (0);
}

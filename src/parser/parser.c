/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:52:05 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/19 20:39:54 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

bool	validate_ipv4(const char *str)
{
	struct in_addr	addr;

	if (!str || ft_strlen(str) == 0)
		return (false);
	return (inet_pton(AF_INET, str, &addr) == 1);
}

bool	validate_hostname(const char *str)
{
	int		i;
	char	prev;

	if (!str || ft_strlen(str) == 0)
		return (false);
	if (str[0] == '.' || str[0] == '-')
		return (false);
	i = 0;
	prev = '\0';
	while (str[i])
	{
		if (!(ft_isalnum((unsigned char)str[i]) || str[i] == '-' || str[i] == '.'))
			return (false);
		if (str[i] == '.' && prev == '.')
			return (false);
		prev = str[i];
		i++;
	}
	if (prev == '.' || prev == '-')
		return (false);
	return (true);
}

void	parse_option(t_ping *ping, char *option)
{
	if (ft_strcmp(option, "-v") == 0)
		ping->verbose = 1;
	else if (ft_strcmp(option, "-?") == 0)
		ping->help = 1;
	else
		ping->error_message = ft_strdup(RED"Unknown option\n"RESET);
}

void	parse_target(t_ping *ping, char *target)
{
	bool	ipv4;
	bool	hostname;
	char	*ipv4_str;

	ipv4 = validate_ipv4(target);
	hostname = validate_hostname(target);
	if (!hostname && !ipv4)
	{
		ping->error_message = ft_strdup(RED"Unknown option\n"RESET);
	}
	else
	{
		if (ipv4)
		{
			ipv4_str = ft_strdup(target);
			if (!ipv4_str)
			{
				ping->error_message = ft_strdup(RED"Memory allocation failed\n"RESET);
				return ;
			}
			ping->target = ipv4_str;
		}
		else
		{
			ping->target = ft_strdup(target);
			if (!ping->target)
			{
				ping->error_message = ft_strdup(RED"Memory allocation failed\n"RESET);
				return ;
			}
		}
	}
}

t_ping	*parse_arguments(t_ping *ping, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			continue ;
		}
		if (argv[i][0] == '-')
		{
			parse_option(ping, argv[i]);
		}
		else
		{
			parse_target(ping, argv[i]);
			break ;
		}
	}
	return (ping);
}

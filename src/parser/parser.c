/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:52:05 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 18:31:45 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static void	set_error(t_ping *ping, t_error_code code, char *arg)
{
	if (ping->error_code == ERR_NONE)
	{
		ping->error_code = code;
		ping->error_arg = arg;
	}
}

bool	parse_option(t_ping *ping, char *option)
{
	if (ft_strcmp(option, "-v") == 0)
		ping->verbose = 1;
	else if (ft_strcmp(option, "-?") == 0)
		ping->help = 1;
	else if (ft_strcmp(option, "--") == 0)
		return (true);
	else
		set_error(ping, ERR_UNKNOWN_OPTION, option);
	return (false);
}

bool	parse_target(t_ping *ping, char *target)
{
	if (ping->error_code != ERR_NONE)
		return (false);
	ping->target = ft_strdup(target);
	if (!ping->target)
	{
		set_error(ping, ERR_MALLOC_FAILED, NULL);
		return (false);
	}
	return (true);
}

void	parse_argument(t_ping *ping, char *arg, bool *dash, bool *has_target)
{
	if (*dash)
	{
		if (!*has_target)
			*has_target = parse_target(ping, arg);
		else
			set_error(ping, ERR_TOO_MANY_ARGS, NULL);
	}
	else if (arg[0] == '-')
	{
		if (parse_option(ping, arg))
			*dash = true;
	}
	else
	{
		if (!*has_target)
			*has_target = parse_target(ping, arg);
		else
			set_error(ping, ERR_TOO_MANY_ARGS, NULL);
	}
}

t_ping	*parse_arguments(t_ping *ping, int argc, char **argv)
{
	int		i;
	bool	dash;
	bool	has_target;

	i = 0;
	dash = false;
	has_target = false;
	while (++i < argc)
	{
		parse_argument(ping, argv[i], &dash, &has_target);
		if (ping->error_code != ERR_NONE)
			break ;
	}
	if (!ping->help && ping->target == NULL && ping->error_code == ERR_NONE)
		set_error(ping, ERR_INVALID_HOST, NULL);
	return (ping);
}

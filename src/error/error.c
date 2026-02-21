/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:38:49 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 20:10:55 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	set_error(t_ping *ping, t_error_code code, char *arg)
{
	if (ping->error_code == ERR_NONE)
	{
		ping->error_code = code;
		ping->er_msg = arg;
	}
}

static void	error_unknown_option(const char *prog, char *arg)
{
	const char	*opt;

	opt = arg;
	if (opt && opt[0] == '-' && opt[1] != '\0')
		opt = opt + 1;
	if (opt)
		ft_fprintf(2, RED"%s: invalid option '-%s'\n"RESET, prog, opt);
	else
		ft_fprintf(2, RED"%s: invalid option '-%s'\n"RESET, prog, "");
}

static void	error_invalid_host(const char *prog, char *arg)
{
	if (arg)
		ft_fprintf(2, RED"%s: %s: Name or service not known\n"RESET, prog, arg);
	else
		ft_fprintf(2, RED"%s: %s: Name or service not known\n"RESET, prog, "");
}

void	print_error(t_ping *ping, const char *prog)
{
	if (ping->error_code == ERR_UNKNOWN_OPTION)
		error_unknown_option(prog, ping->er_msg);
	else if (ping->error_code == ERR_INVALID_HOST)
		error_invalid_host(prog, ping->er_msg);
	else if (ping->error_code == ERR_NO_HOST)
		ft_fprintf(2, RED"%s: no host specified\n"RESET, prog);
	else if (ping->error_code == ERR_TOO_MANY_ARGS)
		ft_fprintf(2, RED"%s: too many arguments\n"RESET, prog);
	else if (ping->error_code == ERR_MALLOC_FAILED)
		ft_fprintf(2, RED"%s: memory allocation failed\n"RESET, prog);
	else if (ping->error_code == ERR_SOCKET_FAILED)
		ft_fprintf(2, RED"%s: socket creation failed\n"RESET, prog);
	else
		ft_fprintf(2, RED"%s: invalid arguments\n"RESET, prog);
}

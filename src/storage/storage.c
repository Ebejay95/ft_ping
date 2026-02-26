/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:06:10 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/26 19:13:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	initialize_ping(t_ping *ping)
{
	ping->target = NULL;
	ping->verbose = 0;
	ping->help = 0;
	ping->count = 0;
	ping->er_msg = NULL;
	ping->error_code = ERR_NONE;
}

void	clean_ping(t_ping	*ping)
{
	if (ping->target != NULL)
	{
		free(ping->target);
	}
	if (ping != NULL)
	{
		free(ping);
	}
}

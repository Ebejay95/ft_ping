/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:34:08 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 18:57:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	run_ping(t_ping *ping)
{	
	(void)ping;
	ft_printf(YELLOW"Running ping to %s\n"RESET, ping->target);
}

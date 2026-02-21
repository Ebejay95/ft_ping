/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:20:12 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 18:27:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	ping_help(void)
{
	ft_printf(CYAN "🖥️ ──📦────────── 🛰️\n" RESET);
	ft_printf(CYAN "Usage: ft_ping [options] <destination>\n" RESET);
	ft_printf(CYAN "Options:\n" RESET);
	ft_printf(CYAN "  -v\t\tVerbose output\n" RESET);
	ft_printf(CYAN "  -?\t\tShow this help message\n" RESET);
}

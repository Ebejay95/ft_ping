/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:17:34 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/19 20:39:12 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# include <stdbool.h>
# include "libft.h"
# include <arpa/inet.h>

typedef struct s_ping
{
	char	*target;
	int		verbose;
	int		help;
	char	*error_message;
}	t_ping;

t_ping	*parse_arguments(t_ping *ping, int argc, char **argv);

#endif

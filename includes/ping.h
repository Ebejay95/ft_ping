/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:17:34 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 20:12:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# include <stdbool.h>
# include "libft.h"
# include <arpa/inet.h>
# include <netdb.h>

typedef struct sockaddr_in	t_sockaddr_in;

typedef enum e_error_code
{
	ERR_NONE,
	ERR_UNKNOWN_OPTION,
	ERR_INVALID_HOST,
	ERR_NO_HOST,
	ERR_TOO_MANY_ARGS,
	ERR_MALLOC_FAILED,
	ERR_SOCKET_FAILED
}	t_error_code;	

typedef struct s_ping
{
	char				*target;
	int					verbose;
	int					help;
	char				*er_msg;
	t_sockaddr_in		resolved_addr;
	t_error_code		error_code;	
}	t_ping;

t_ping	*parse_arguments(t_ping *ping, int argc, char **argv);

void	initialize_ping(t_ping *ping);
void	clean_ping(t_ping *ping);
void	print_error(t_ping *ping, const char *prog);
void	set_error(t_ping *ping, t_error_code code, char *arg);
void	ping_help(void);
int		resolve_target(t_ping *ping);
int		run_ping(t_ping *ping);

#endif

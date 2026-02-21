/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:17:34 by jeberle           #+#    #+#             */
/*   Updated: 2026/02/21 18:24:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# include <stdbool.h>
# include "libft.h"
# include <arpa/inet.h>

typedef enum e_error_code
{
	ERR_NONE,
	ERR_UNKNOWN_OPTION,
	ERR_INVALID_HOST,
	ERR_TOO_MANY_ARGS,
	ERR_MALLOC_FAILED
}	t_error_code;	

typedef struct s_ping
{
	char			*target;
	int				verbose;
	int				help;
	char			*error_arg;
	t_error_code	error_code;	
}	t_ping;

t_ping	*parse_arguments(t_ping *ping, int argc, char **argv);

void	initialize_ping(t_ping *ping);
void	clean_ping(t_ping *ping);
void	print_error(t_ping *ping, const char *prog);
void	ping_help(void);

#endif

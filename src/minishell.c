/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:37:34 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/08 20:29:19 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(void)
{
	load_history_from_file(HISTORY_FD);
	while (true)
	{
		//TODO: Show prompt (readline)
		prompt();
		//TODO: Parsing
		//TODO: Signals
		//TODO: Execution
		//TODO: BUILT-INS
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}

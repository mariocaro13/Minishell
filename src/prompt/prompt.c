/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:17:45 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/08 20:39:00 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	char	*input;

	input = readline(GREEN_BOLD PROMPT RESET_COLOR);
	if (input && *input)
	{
		add_history(input);
		save_history_to_file(HISTORY_FD, input);
	}
}

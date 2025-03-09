/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:17:45 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/09 01:11:26 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	char	*input;
	bool	is_space;
	int		i;

	input = readline(GREEN_BOLD PROMPT RESET_COLOR);
	if (input && *input)
	{
		i = 0;
		is_space = true;
		while (input[i])
		{
			if (!ft_isspace((unsigned char)input[i]))
				is_space = false;
			i++;
		}
		if (is_space)
			return ;
		add_history(input);
		save_history_to_file(HISTORY_FD, input);
	}
}

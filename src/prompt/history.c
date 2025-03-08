/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:38:40 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/08 22:30:52 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_history_to_file(const char *filename, const char *input)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(ERR_O_FILE);
		return ;
	}
	//FIXME: replace strlen to ft_strlen
	write(fd, input, strlen(input));
	write(fd, "\n", 1);
	close(fd);
}

void	load_history_from_file(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

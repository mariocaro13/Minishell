/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:38:40 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/09 01:11:01 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_history_to_file(const char *filename, const char *input)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(ERR_O_FILE);
		return ;
	}
	write(fd, input, ft_strlen(input));
	if (input[ft_strlen(input) - 1] != '\n')
		write(fd, "\n", 1);
	close(fd);
}

void	load_history_from_file(const char *filename)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

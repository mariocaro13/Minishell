/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:44:22 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/03/08 22:39:36 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/**
*  ___ _   _  ____ _    _   _ ____  _____ ____  
* |_ _| \ | |/ ___| |  | | | |  _ \| ____/ ___| 
*  | ||  \| | |   | |  | | | | | | |  _| \___ \ 
*  | || |\  | |___| |__| |_| | |_| | |___ ___) |
* |___|_| \_|\____|_____\___/|____/|_____|____/ 
*
*/

# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
// Custom libs
# include "libft.h"
# include "colors.h"
# include "messages.h"

/**
*  ____  _____ _____ ___ _   _ _____ ____  
* |  _ \| ____|  ___|_ _| \ | | ____/ ___| 
* | | | |  _| | |_   | ||  \| |  _| \___ \ 
* | |_| | |___|  _|  | || |\  | |___ ___) |
* |____/|_____|_|   |___|_| \_|_____|____/ 
*
*/

/**
*  ____  ____   ___ _____ ___ _______   ______  _____ ____  
* |  _ \|  _ \ / _ \_   _/ _ \_   _\ \ / /  _ \| ____/ ___| 
* | |_) | |_) | | | || || | | || |  \ V /| |_) |  _| \___ \ 
* |  __/|  _ <| |_| || || |_| || |   | | |  __/| |___ ___) |
* |_|   |_| \_\\___/ |_| \___/ |_|   |_| |_|   |_____|____/ 
*
*/

int		minishell(void);

// PROMPT
void	prompt(void);
// HISTORY
void	save_history_to_file(const char *filename, const char *input);
void	load_history_from_file(const char *filename);

#endif

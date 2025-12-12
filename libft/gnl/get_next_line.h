/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:31:46 by selow             #+#    #+#             */
/*   Updated: 2025/08/19 22:06:26 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "../libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char		*read_into_backup(int fd, char *backup);
char		*get_next_line(int fd);
char		*save_remaining(char *saved, char *line);
char		*extract_one_line(char *saved);
char		*free_buffer_and_backup(char **buffer, char **backup);

#endif

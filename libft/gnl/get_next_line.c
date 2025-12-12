/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:50:41 by selow             #+#    #+#             */
/*   Updated: 2025/08/19 22:10:24 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_buffer_and_backup(char **buffer, char **backup)
{
	free(*buffer);
	free(*backup);
	return (NULL);
}

char	*read_into_backup(int fd, char *backup)
{
	int		bytes_read;
	char	*buffer;
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(backup, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_buffer_and_backup(&buffer, &backup));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(backup, buffer);
		if (!temp)
			return (free_buffer_and_backup(&buffer, &backup));
		free(backup);
		backup = temp;
	}
	free(buffer);
	return (backup);
}

char	*extract_one_line(char *saved)
{
	char	*line;
	int		linelen;
	int		j;

	linelen = 0;
	if (!saved)
		return (NULL);
	while (saved[linelen] && saved[linelen] != '\n')
		linelen++;
	line = malloc(linelen + (saved[linelen] == '\n') + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < linelen)
	{
		line[j] = saved[j];
		j++;
	}
	if (saved[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*save_remaining(char *saved, char *line)
{
	int		linelen;
	char	*buffer;

	if (!saved || !line)
		return (NULL);
	linelen = ft_strlen(line);
	if (!saved[linelen])
	{
		free(saved);
		return (NULL);
	}
	buffer = ft_strdup(&saved[linelen]);
	free(saved);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_into_backup(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_one_line(saved);
	saved = save_remaining(saved, line);
	return (line);
}
/*
int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	printf("1st: %s", get_next_line(fd));
	printf("2nd: %s", get_next_line(fd));
	printf("3rd: %s", get_next_line(fd));
	printf("4th: %s", get_next_line(fd));
	printf("5th: %s", get_next_line(fd));
	return 0;
}*/

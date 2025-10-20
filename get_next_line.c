/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:08:31 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/21 00:51:58 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief frees and set a char* to null if not null
 */
static void	del_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

/**
 * @brief reads from fd until a '\n' is in content
 * 
 * @return 0 on success, 1 on error
 */
static int	read_till_newline(int fd, char **content)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*temp;

	if (gnl_strchr(*content, '\n'))
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (1);
	buffer[bytes_read] = '\0';
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		temp = gnl_strjoin(*content, buffer);
		del_str(content);
		*content = temp;
		if (!temp || gnl_strchr(buffer, '\n'))
			break;
	}
	del_str(&buffer);
	if (bytes_read < 0)
		return (1);
	return (0);
}

/**
 * @brief returns a duped string from content start -> '\n'
 * 
 * It will search for a newline character in content:
 * 1. if none is found it means the file hit the end and it returns content.
 * 2. otherwise, it will 'cut' it from content.
 * That means it will dup from content start -> the newline char.
 * Then it will delete that part from content and return the 'cut'
 * part as the result.
 * 
 * @return char* to new string
 */
static char	*get_line(char **content)
{
	char	*newline_pos;
	char	*line;
	char	*tmp;

	if (!content || !*content)
		return (NULL);
	newline_pos = gnl_strchr(*content, '\n');
	if (!newline_pos)
	{
		line = gnl_strdup(*content);
		del_str(content);
		return (line);
	}
	tmp = gnl_strdup(newline_pos + 1);
	if (!tmp)
		return (NULL);
	line = gnl_substr(*content, 0, (newline_pos - *content + 1));
	del_str(content);
	*content = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (del_str(&content), NULL);
	if (read_till_newline(fd, &content))
		return (del_str(&content), NULL);
	result = get_line(&content);
	if (!result || !*result)
		return (del_str(&content), NULL);
	return (result);
}

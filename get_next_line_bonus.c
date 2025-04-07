/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:43:16 by songevor          #+#    #+#             */
/*   Updated: 2024/04/23 19:40:48 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_file(int fd, char *arr)
{
	char	*buffer;
	int		bytes_count;

	bytes_count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (arr == NULL)
		arr = ft_strdup("");
	while (!ft_strchr(arr, '\n') && bytes_count != 0)
	{
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		if (bytes_count < 0)
		{
			free(buffer);
			free(arr);
			return (NULL);
		}
		buffer[bytes_count] = '\0';
		arr = ft_strjoin(arr, buffer);
	}
	free(buffer);
	return (arr);
}

char	*get_line_2(char *arr)
{
	char	*line;
	size_t	i;

	i = 0;
	while (arr[i] != '\n' && arr[i] != '\0')
		i++;
	i++;
	line = ft_substr(arr, 0, i);
	return (line);
}

char	*return_line(char *arr)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (arr[i] != '\n' && arr[i])
		i++;
	tmp = ft_substr(arr, i + 1, ft_strlen(arr));
	free(arr);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*arr[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	arr[fd] = read_from_file(fd, arr[fd]);
	if (!arr[fd] || arr[fd][0] == '\0')
	{
		free(arr[fd]);
		arr[fd] = 0;
		return (NULL);
	}
	line = get_line_2(arr[fd]);
	arr[fd] = return_line(arr[fd]);
	return (line);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		count;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (count < 7)
// 	{
// 		line = get_next_line(fd);
// 		count++;
// 		printf("[%d]:%s", count, line);
// 	}
// 	close(fd);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:33:13 by songevor          #+#    #+#             */
/*   Updated: 2024/03/05 18:33:18 by songevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_line_1(char *arr)
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
	static char	*arr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(arr);
		arr = NULL;
		return (NULL);
	}
	arr = read_from_file(fd, arr);
	if (!arr || arr[0] == '\0')
	{
		free(arr);
		arr = 0;
		return (NULL);
	}
	line = get_line_1(arr);
	arr = return_line(arr);
	return (line);
}
// #include <stdio.h>
// int	main(void)

// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line;
// 	int		count;

// 	count = 0;
// 	fd1 = open("example.txt", O_RDONLY);
// 	fd2 = open("lala.txt", O_RDONLY);
// 	// if (fd1 == -1 )
// 	// {
// 	// 	printf("Error opening file");
// 	// 	return (1);
// 	// }
// 	line = get_next_line(fd2);
// 	count++;
// 	printf("[%d]:%s", count, line);
// 	line = get_next_line(fd1);
// 	count++;
// 	printf("[%d]:%s", count, line);
// 	line = get_next_line(fd2);
// 	count++;
// 	printf("[%d]:%s", count, line);
// 	line = get_next_line(fd1);
// 	count++;
// 	printf("[%d]:%s", count, line);

// 	// while (count < 7)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	line = get_next_line(fd11);
// 	// 	count++;
// 	// 	printf("[%d]:%s", count, line);
// 	// }
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }

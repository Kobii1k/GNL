/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:25 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/27 20:07:40 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_get_after_n(char *buff, int j)
{
	int	i;

	i = 0;
	while (buff[j])
	{
		buff[i] = buff[j];
		i++;
		j++;
	}
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
}

char	*ft_get_line_to_n(char *buff, char *line)
{
	int		i;
	int		j;
	char	*str;

	j = ft_strlen(line) - 1;
	while (j >= 0 && line[j] != '\n')
		j--;
	if (j < 0)
		return (line);
	i = 0;
	str = malloc(sizeof(char) * j + 2);
	while (i < j)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	ft_get_after_n(buff, j);
	free(line);
	return (str);
}

int	is_next_line(char *buff)
{
	unsigned int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_to_n(int fd, char *buff, char *line)
{
	ssize_t	len;

	len = read(fd, buff, BUFFER_SIZE);
	while (len != 0 && !is_next_line(buff))
	{
		line = ft_strjoin(line, buff, len);
		if (!line)
			return (NULL);
		len = read(fd, buff, BUFFER_SIZE);
	}
	if (len != 0)
		line = ft_strjoin(line, buff, len);
	else
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_read_to_n(fd, buff, line);
	if (!line)
		return (NULL);
	line = ft_get_line_to_n(buff, line);
	if (!line)
		return (NULL);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int		fd;
	char	*str;

	fd = open("ayo.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	free(str);
}

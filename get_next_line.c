/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:25 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/24 14:47:05 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		len;

	if (fd == -1)
		return (NULL);
	line = malloc(sizeof(char));
	line[0] = '\0';
	while ((len = read(fd, buff, BUFFER_SIZE)))
		line = ft_strjoin(line, buff);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int	fd;

	fd = open("ayo.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}

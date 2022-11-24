/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:25 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/24 17:54:57 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_to_n(fd, buff);
	line = ft_get_line_to_n(buff, line);
	ft_get_after_n(buff);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int		fd;
	char	*str;

	fd = open("ayo.txt", O_RDONLY);
	while (str = get_next_line(fd))
		printf("%s\n", str);
}

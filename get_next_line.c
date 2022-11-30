/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:25 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/30 15:53:00 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cleanup_buffer(char *buff)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (buff[j] != '\n')
		j++;
	while (++j <= BUFFER_SIZE)
	{
		buff[i] = buff[j];
		i++;
	}
	buff[i] = '\0';
}

char	*ft_cleanup_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (line);
	else
	{
		j = 0;
		tmp = malloc(sizeof(char) * (i + 2));
		if (!tmp)
			return (free(line), NULL);
		while (j <= i)
		{
			tmp[j] = line[j];
			j++;
		}
		tmp[j] = '\0';
		free(line);
		return (tmp);
	}
}

char	*ft_read_nl(int fd, char *buff, char *line)
{
	int		len;
	char	*tmp;

	len = 1;
	while (len != 0 && ft_is_nl(buff) == -1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			ft_bzero(buff, BUFFER_SIZE);
			return (NULL);
		}
		if (len == 0)
			return (NULL);
		buff[len] = '\0';
		tmp = ft_strjoin(line, buff, len);
		free(line);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	return (line);
}

char	*ft_read(int fd, char *buff)
{
	char	*line;
	char	*tmp;

	line = NULL;
	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (buff)
	{
		line = ft_strjoin(tmp, buff, ft_strlen(buff));
		free(tmp);
		if (!line)
			return (NULL);
	}
	tmp = ft_read_nl(fd, buff, line);
	if (!tmp)
		return (free(line), NULL);
	line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_read(fd, buff);
	if (!line || !line[0])
		return (NULL);
	tmp = ft_cleanup_line(line);
	if (!tmp)
		return (NULL);
	ft_cleanup_buffer(buff);
	return (tmp);
}

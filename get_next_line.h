/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:07 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/24 17:57:27 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_to_n(int fd, char *buff);
char	*ft_get_line_to_n(char *buff, char *line);
void	ft_get_after_n(char *buff);

size_t	ft_strlen(const char *s)
char	*ft_strjoin(char const *s1, char const *s2);

#endif

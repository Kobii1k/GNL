/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:07 by mgagne            #+#    #+#             */
/*   Updated: 2022/12/01 18:16:40 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buff);
char	*ft_read_nl(int fd, char *buff, char *line);
int		ft_is_nl(char *buff);
char	*ft_cleanup_line(char *line);
void	ft_cleanup_buffer(char *buff);

size_t	ft_strlen(const char *s);
char	*ft_strjoin_len(char *s1, char *s2, int len_s2);
char	*ft_strjoin_free(char *s1, char *s2, int len_s2);
void	ft_bzero(void *s, size_t n);

#endif

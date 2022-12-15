/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:03 by mgagne            #+#    #+#             */
/*   Updated: 2022/12/01 19:00:12 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
			i++;
	return (i);
}

char	*ft_strjoin_len(char *s1, char *s2, int len_s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 && s2)
	{
		str = malloc((ft_strlen(s1) + len_s2 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
				str[j++] = s1[i++];
		i = 0;
		while (s2[i])
				str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2, int len_s2)
{
	char	*new;

	new = ft_strjoin_len(s1, s2, len_s2);
	if (!new)
		return (NULL);
	free(s1);
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointer;

	pointer = s;
	while (n)
	{
		*pointer = 0;
		pointer++;
		n--;
	}
}

int	ft_is_nl(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

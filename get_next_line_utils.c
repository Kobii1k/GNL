/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:03 by mgagne            #+#    #+#             */
/*   Updated: 2022/11/22 13:52:42 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str;
        int             i;
        int             j;

        if (s1 && s2)
        {
                i = ft_strlen(s1) + ft_strlen(s2) + 1;
                str = malloc(i * sizeof(char));
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


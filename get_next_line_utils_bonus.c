/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:30:56 by framador          #+#    #+#             */
/*   Updated: 2023/11/17 16:54:19 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
	{
		if (s[i] == 10)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}

void	ft_buffflusher(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buff[i] != 10)
		i++;
	if (buff[i] == 10 && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		buff[j] = buff[i];
		buff[i] = 0;
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
		buff[j++] = 0;
}

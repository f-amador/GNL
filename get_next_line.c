/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:07:37 by framador          #+#    #+#             */
/*   Updated: 2023/11/17 16:08:41 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (BUFFER_SIZE > 0)
		{
			ft_buffflusher(buff);
			return (NULL);
		}
	}
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff);
		ft_buffflusher(buff);
		if (str[ft_strlen(str) - 1] == 10)
			break ;
	}
	return (str);
}

// int main(void)
// {
// 	int fd;
// 	char *str;
//     int i;

//     i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("line->%d: %s", i, str);
// 		free(str);
//         i++;
// 	}
// 	return (0);
// }

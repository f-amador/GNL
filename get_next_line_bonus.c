/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:30:43 by framador          #+#    #+#             */
/*   Updated: 2023/11/17 17:45:20 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		if (BUFFER_SIZE > 0)
		{
			ft_buffflusher(buff[fd]);
			return (NULL);
		}
	}
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff[fd]);
		ft_buffflusher(buff[fd]);
		if (str[ft_strlen(str) - 1] == 10)
			break ;
	}
	return (str);
}

// int main(void)
// {
//     int fd1, fd2, fd3;
//     char *line1, *line2, *line3;

//     // Open the files
//     fd1 = open("a.txt", O_RDONLY);
//     fd2 = open("b.txt", O_RDONLY);
//     fd3 = open("c.txt", O_RDONLY);

//     // Read and print one line from each file in a round-robin fashion
//     while (1)
//     {
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		line3 = get_next_line(fd3);
//         if (line1 != NULL)
//         {
//             printf("%s", line1);
//             free(line1);
//         }
//         if (line2 != NULL)
//         {
//             printf("%s", line2);
//             free(line2);
//         }
//         if (line3 != NULL)
//         {
//             printf("%s", line3);
//             free(line3);
//         }
// 		if (line1 == NULL && line2 == NULL && line3 == NULL)
// 			break ;
//     }

//     // Close the files
//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:58:30 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/27 23:00:45 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	int		counter;

	counter = 0;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	while (counter++ < 5)
	{
		line = get_next_line(fd);
		printf("\nNext line 1: %s\n", line);
		line = get_next_line(fd2);
		printf("\nNext line 2: %s\n", line);
		line = get_next_line(fd3);
		printf("\nNext line 3: %s\n", line);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}

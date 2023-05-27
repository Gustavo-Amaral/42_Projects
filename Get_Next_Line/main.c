/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:16:43 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/26 20:27:34 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	fd = open("text.txt", O_RDONLY);
	while (counter++ < 10)
	{
		line = get_next_line(fd);
		printf("\nNext line: %s\n", line);
	}
	close(fd);
	return (0);
}

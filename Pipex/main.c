/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:22 by gamaral           #+#    #+#             */
/*   Updated: 2023/12/03 20:55:25 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/Pipex.h"

int	main(void)
{
	// open() returns a file descriptor file_desc to a  
    // the file "dup.txt" here" 
  
    int file_desc = open("dup.txt", O_WRONLY | O_APPEND); 
      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
      
    // dup() will create the copy of file_desc as the copy_desc 
    // then both can be used interchangeably. 
  
    int copy_desc = dup2(file_desc, 1); 
	int copy_desc2 = dup2(file_desc, 5); 
          
    // write() will write the given string into the file 
    // referred by the file descriptors 
  
    write(copy_desc,"This will be output to the file named dup.txt\n", 46); 
	write(copy_desc2,"This will be output again to the file named dup.txt\n", 52);
    write(file_desc,"This will also be output to the file named dup.txt\n", 51);
	printf("we did not have an Error opening the file\n");  
	return (0);
}

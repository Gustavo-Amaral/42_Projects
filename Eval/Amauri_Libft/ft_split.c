/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:13:43 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/22 18:41:58 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(const char *str, char c)
{
	int	word_counter;
	int	i;

	i = 0;
	word_counter = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			word_counter ++;
		i++;
	}
	return (word_counter);
}

static int	letters_counter(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc((words_counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, letters_counter(&s[i], c));
			if (!str[j])
				return (ft_free(str, j));
			j++;
			i += letters_counter(&s[i], c);
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
/*
//function descrition
 //ft_split divides a string s into an array of substrings using delimiter c. 
 //It counts words, allocates memory, and populates the array, 
 //handling errors by freeing memory.
#include <stdio.h>
 
int	main(void)
{
	
	//test word count
	//char *count_this = "ccc ccc";
	//char space = ' ';
	//printf("should return 2 => %d\n", count_words(count_this, space));
	
	//test ft_split
	char *input1 = " This is SPARTAA aa AAA";
	char delimiter1 = ' ';
	
	int 	i;
	char **result1 = ft_split(input1, delimiter1);
	i = 0;
	while (result1[i] != NULL)
	{
		printf("%s\n", result1[i]);
		i++;
	} 
	
}
 */
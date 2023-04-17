/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:20:01 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 21:39:00 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst,const char *src, size_t size)
{
	size_t	offset;

	offset = 0;
	if (size > 0)
	{
		while (offset < (size - 1))
		{
			dst[offset] = src[offset];
			offset++;
		}
	}
	dst[offset] = '\0';
	offset = ft_strlen(src);
	return (offset);
}

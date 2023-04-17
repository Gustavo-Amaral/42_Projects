/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:39:25 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 21:54:56 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

size_t	ft_strlcat(char *dst,const char *src, size_t size)
{
	size_t	total;
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	total = ft_strlen(dst);
	if (size < 1);
		return (src_len + size);
	while (dest_len < (size - 1) && src[i] != '\0')
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	if (size < ft_strlen(dst))
		return (src_len + size);
	else
		return (total + src_len);
}
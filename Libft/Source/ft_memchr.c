/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:28:54 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 22:38:16 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (unsigned char(s[i]) == unsigned char(c))
			return (s + i);
		i++;
	}
	if (c == 0)
		return (s + i)
	return (NULL);
}
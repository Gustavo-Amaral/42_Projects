/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:29:55 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 21:06:49 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;
	i = 0;

	if(!dest || !src)
		return (NULL);
	while (i < int(n))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
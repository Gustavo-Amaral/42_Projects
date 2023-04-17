/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:36:55 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 21:06:02 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*aux;
	int		i;

	if(!dest || !src)
		return (NULL);
	i = 0;
	while (i < int(n))
	{
		aux[i] = src[i];
		dest[i] = aux[i];
		i++;
	}
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:15:30 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 22:36:06 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	flag;
	int	aux;

	i = 0;
	flag = 0;
	aux = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			aux = i;
			flag = 1;
		}
		i++;
	}
	if (flag)
		return (s + aux);
	if (c == 0)
		return (s + i)
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:52:04 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 18:14:50 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revstr(char *str)
{
	int		i;
	int		len;
	char	aux;

	i = 0;
	len = ft_strlen(str);
	while (i < (len / 2))
	{
		aux = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = aux;
		i++;
	}
}

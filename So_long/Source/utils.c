/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:36:16 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 21:24:14 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

char	*read_file(int fildes, t_list **lst)
{
	int		read_val;
	char	*str;
	char	*tmp;
	char	buff[1084];

	str = NULL;
	read_val = 1;
	while (read_val)
	{
		read_val = read(fildes, buff, 1084);
		buff[read_val] = '\0';
		tmp = str;
		ft_lstadd_back(lst, ft_lstnew(str));
		str = ft_strjoin(tmp, buff);
	}
	return (str);
}

char	*ft_str_add(char *str, int n, char c, t_list **lst)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	new = malloc(sizeof(char) * (len + n + 1));
	ft_lstadd_back(lst, ft_lstnew(new));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (i < len + n)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	random_seed(int max, int fildes)
{
	char	buff[1];
	int		read_val;
	int		c;

	read_val = read(fildes, buff, 1);
	if (read_val < 1)
		return (ft_atoi("0123456789"[max % fildes]));
	c = buff[0];
	while (c >= (UCHAR_MAX + 1) / max * max)
	{
	}
	if (c < 0)
		c *= -1;
	return (c % max);
}

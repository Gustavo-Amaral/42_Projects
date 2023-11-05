/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:00:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 17:17:10 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	nulling_elements(void *arg)
{
	free(arg);
	arg = NULL;
}

void	lst_free(t_list **lst)
{
	ft_lstclear(lst, nulling_elements);
	free(lst);
}

void	array_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

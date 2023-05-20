/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:29:15 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/13 22:37:15 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char	*format, ...);
int	ft_print_char(char c);
int	ft_print_hex(unsigned int num, const char c);
int	ft_print_nbr(int num);
int	ft_print_ptr(void *ptr);
int	ft_print_str(char *c);
int	ft_print_unsigned(unsigned int num);

#endif
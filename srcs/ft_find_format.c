/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:00:09 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/16 17:15:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_find_format(t_flags *flag_tab, const char *format, int index)
{
	
	while (format[index] != '%' || ft_isalpha(format[index]) == 1)
	{
		if (format[index] == '-')
			index = ft_minus_flag(flag_tab, format, index);
		else if (format[index] == '*')
			index = ft_wildcard_flag(flag_tab, format, index);
		else if (format[index] == '0')
			index = ft_zero_flag(flag_tab, format, index);
		else if (format[index] == '.')
			index = ft_point_flag(flag_tab, format, index);
	}
	return (index);
}
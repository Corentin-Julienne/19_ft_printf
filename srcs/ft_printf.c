/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:47:55 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/21 15:08:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" // check the path

t_flags	*ft_initialize_flaglist(t_flags *flag_tab) // initializing struct to 0
{
	flag_tab->minus = 0;
	flag_tab->is_zero = 0;
	flag_tab->point = 0;
	flag_tab->wildcard = 0; 
	flag_tab->rtn = 0;
	flag_tab->width = 0;
	flag_tab->precisions = 0;	
	return (flag_tab);
}

int	ft_printf(const char *format, ...)
{
	t_flags		*flag_tab;
	size_t		i;
	int			output;	

	if (!format)
		return (1);
	flag_tab = (t_flags*)malloc(sizeof(t_flags));
	if (!flag_tab)
		return (1); // means something fucked up
	ft_initialize_flaglist(flag_tab); // initialize values to 0
	va_start(flag_tab->args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%') // indicates that a flag or conversion is present
			ft_find_format(flag_tab, format, (int)(i + 1)); // TODO
		else
			output += write(1, &format[i], 1); // just print it
		i++;
	}
	va_end(flag_tab->args);
	free(flag_tab); // get rid of flag_tab
	return (output);
}

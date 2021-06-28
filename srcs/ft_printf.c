/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:47:55 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/28 16:04:54 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" // check the path

void	ft_initialize_flaglist(t_flags *flag_tab) // initializing struct to 0
{
	flag_tab->minus = 0;
	flag_tab->is_zero = 0;
	flag_tab->point = 0;
	flag_tab->wildcard = 0; 
	flag_tab->rtn = 0;
	flag_tab->width = 0;
	flag_tab->precisions = 0;	
}

void	ft_reset_flaglist(t_flags *flag_tab) // reset between arguments
{
	flag_tab->minus = 0;
	flag_tab->is_zero = 0;
	flag_tab->point = 0;
	flag_tab->wildcard = 0; 
	flag_tab->width = 0;
	flag_tab->precisions = 0;
}

int	ft_printf(const char *format, ...)
{
	t_flags		*flag_tab;
	size_t		i;
	int			output;	

	flag_tab = (t_flags*)malloc(sizeof(t_flags));
	if (!flag_tab)
		return (-1); // means something fucked up
	ft_initialize_flaglist(flag_tab); // initialize values to 0
	flag_tab->format = format;
	va_start(flag_tab->args, format);
	i = 0;
	while (flag_tab->format[i])
	{
		if (flag_tab->format[i] == '%') // indicates that a flag or conversion is present
			ft_find_format(flag_tab, (int)(i + 1)); // TODO
		else
		{
			ft_putchar_fd(flag_tab->format[i], 1);
			flag_tab->rtn++;
		}	
		i++;
	}
	output = flag_tab->rtn;
	va_end(flag_tab->args);
	free(flag_tab); // get rid of flag_tab
	return (output);
}

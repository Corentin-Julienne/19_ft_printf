/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:47:55 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/15 17:19:34 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // check the path

t_flags	*ft_initiaize_flaglist(t_flags *flag_tab) // initializing struct to 0
{
	flag_tab->tl_return = 0;
	flag_tab->percent = 0;
	flag_tab->minus = 0;
	flag_tab->is_zero = 0;
	flag_tab->point = 0;
	flag_tab->wildcard = 0; 	
	return (flag_tab);
}

int	ft_printf(const char *format, ...)
{
	t_flags		*flag_tab;
	size_t		i;
	int			output;	

	flag_tab = (t_flags*)malloc(sizeof(t_flags));
	if (!flag_tab)
		return (1); // means something fucked up
	ft_initiaize_flaglist(flag_tab); // initialize values to 0
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			; // TODO
		else
			output += write(1, &format[i], 1); // just print it
		i++;
	}
	free(flag_tab); // get rid of flag_tab
}
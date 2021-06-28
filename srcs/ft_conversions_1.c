/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:56:53 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/28 15:58:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" // check the PATH

// functions that can handle the printing and format of conversion operators

void	ft_print_int(t_flags *flag_tab)
{
	// TODO
	int	output;
	
	output = va_arg(t_flags->args, int);
	ft_putnbr_fd(output, 1);
}

void	ft_print_unsigned_int(t_flags *flag_tab)
{
	// TODO
	unsigned int	output;
	
	output = va_arg(t_flags->args, unsigned int);
	ft_putnbr_fd((int)output, 1);
}

void	ft_print_char(t_flags *flag_tab)
{
	// TODO
	char	tmp;
	char	output;

	tmp = va_arg(t_flags->args, char);
	output = tmp;
	ft_putchar_fd(output, 1);
}

void	ft_print_string(t_flags *flag_tab)
{
	char	*str;
	
	str = va_arg(t_flags->args, char *);
	if (str = NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
}

void	ft_print_pointer_address(t_flags *flag_tab)
{
	// TODO
}

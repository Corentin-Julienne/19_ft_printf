/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:47:53 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/28 16:05:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 

typedef struct s_flags                       
{                        
    va_list		args;			// initialize variadic list
	const char	*format;		//the string contains as arg
	// flags
	int			minus;			// the minus ('-') flag
	int			is_zero;		// the 0 flag
	int			point;			// the point ('.') flag
	int			wildcard; 		// the wildcard ('*') flag
	// return value
	int			rtn;			// the return value 
	// width and precision
	int			width;			// the width value
	int			precisions;		// the precision value
}    		   t_flags;

int			ft_printf(const char *format, ...);
void		ft_initialize_flaglist(t_flags *flag_tab);
void		ft_putnbr_base(int nbr, char *base);
void		ft_print_hexadecimal(t_flags *t_flags);
void		ft_print_capital_hexadecimal(t_flags *t_flags);
void		ft_print_int(t_flags *flag_tab);
void		ft_print_unsigned_int(t_flags *flag_tab);
void		ft_print_char(t_flags *flag_tab);
void		ft_print_string(t_flags *flag_tab);
void		ft_print_pointer_address(t_flags *flag_tab);
int			ft_zero_flag(t_flags *flag_tab, const char *format, int index);
int			ft_wildcard_flag(t_flags *flag_tab, const char *format, int index);
int			ft_minus_flag(t_flags *flag_tab, const char *format, int index);
int 		ft_point_flag(t_flags *flag_tab, const char *format, int index);

#endif

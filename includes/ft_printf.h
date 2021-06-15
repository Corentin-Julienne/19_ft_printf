/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:47:53 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/15 16:33:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags                       
{                        
    va_list		args;
	int			tl_return;      // the actual return value (AKA total length)
	int			percent;		// % flag indicating followin char is a proper flag
	int			minus;			// the minus ('-') flag
	int			is_zero;		// the 0 flag
	int			point;			// the point ('.') flag
	int			wildcard; 		// the wildcard ('*') flag     
}    		   t_flags;

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 

int	ft_printf(const char *format, ...);

#endif

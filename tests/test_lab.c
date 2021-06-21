/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:22:27 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/21 13:50:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// testlab to see the behaviour of real printf function

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int		output;
	// int		example;

	// example = 123;
	printf("%11%\n");
	output = printf("%11%\n");
	printf("%d", output);
	
	return (0);
}
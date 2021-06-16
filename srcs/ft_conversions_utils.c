/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:05:53 by cjulienn          #+#    #+#             */
/*   Updated: 2021/06/16 12:53:21 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" // check the path

static void	ft_putchar(char c) // to testing purposes, kill after
{
	write(1, &c, 1);
}

static void	ft_base_converter(int nb, char *base, int base_size)
{
	if (nb >= base_size)
	{
		ft_base_converter((nb / base_size), base, base_size);
		ft_putchar(base[(nb % base_size)]);
	}
	else
		ft_putchar(base[nb]);
}

static int	ft_verificator_2(char *base, int res)
{
	int i;

	i = 0;
	while(base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			res = -1;
		i++;
	}
	return (res);
}

static int	ft_verificator(char *base)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 1;
	res = 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				if (i != j)
					res = -1;
			j++;
		}
		i++;
		j = 0;
	}
	res = ft_verificator_2(base, res);
	return (res);
}

void	ft_putnbr_base(int nbr, char *base) // everything yet to test !!!!
{
	int		verificator;
	int		base_size;
	long	nb;

	nb = nbr;
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	verificator = ft_verificator(base);
	if (base[0] == '\0')
		verificator = -1;
	if (base[0] != '\0')
		if (base[1] == '\0')
			verificator = -1;
	if (verificator > 0)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		ft_base_converter(nb, base, base_size);
	}
}

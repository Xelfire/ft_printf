/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdussoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:42:40 by tdussoye          #+#    #+#             */
/*   Updated: 2022/12/28 15:51:25 by tdussoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

void	ft_putchar_cpt(char c, int *cpt)
{
	write(1, &c, 1);
	*cpt = *cpt + 1;
}

void	ft_putstr_cpt(const char *s, int *cpt)
{
	int			j;

	j = 0;
	while (s[j])
	{
		ft_putchar_cpt((unsigned char)s[j], cpt);
		j++;
	}
}

void	ft_putnbr_cpt(long long nb, int *cpt)
{
	if (nb < 0)
	{
		ft_putchar_cpt('-', cpt);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_cpt(nb / 10, cpt);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar_cpt(nb + 48, cpt);
	}
}

void	ft_putnbr_hexa(char c, long long nb, int *cpt)
{
	if (c == 'p')
	{
		ft_putstr_cpt("0x", cpt);
		c = 'x';
		nb = (long int)nb;
	}
	if (nb < 0)
	{
		ft_putchar_cpt('-', cpt);
		nb = -nb;
	}
	if (nb >= 16)
	{
		ft_putnbr_hexa(c, nb / 16, cpt);
		nb = nb % 16;
	}
	if ((nb >= 10) && (nb <= 16) && (c == 'x'))
		ft_putchar_cpt(nb + 87, cpt);
	else if ((nb >= 10) && (nb <= 16))
		ft_putchar_cpt(nb + 55, cpt);
	else if (nb < 10)
		ft_putchar_cpt(nb + 48, cpt);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cpt;
	va_list	args;

	va_start(args, str);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c' && ++i)
			ft_putchar_cpt((unsigned char) va_arg(args, int), &cpt);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr_cpti(va_arg(args, char *), &i, &cpt);
		else if (str[i] == '%' && (str[i + 1] == 'p' || str[i + 1] == 'i' || \
		str[i + 1] == 'd' || str[i + 1] == 'u' || str[i + 1] == 'x' || \
		str[i + 1] == 'X'))
			ft_choix(str[i + 1], va_arg(args, long long int), &i, &cpt);
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar_cpt(str[i++], &cpt);
		else
			ft_putchar_cpt(str[i], &cpt);
		i++;
	}
	va_end(args);
	return (cpt);
}

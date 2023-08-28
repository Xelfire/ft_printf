/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdussoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:49:01 by tdussoye          #+#    #+#             */
/*   Updated: 2022/12/28 15:49:20 by tdussoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_cpti(const char *s, int *i, int *cpt)
{
	int			j;
	const char	*str = "(null)";

	j = 0;
	if (!s)
		s = (char *)str;
	while (s[j])
	{
		ft_putchar_cpt((unsigned char)s[j], cpt);
		j++;
	}
	*i = *i + 1;
}

void	ft_choix(char c, long int nb, int *i, int *cpt)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_cpt((int)nb, cpt);
	else if (c == 'u')
		ft_putnbr_cpt((unsigned int)nb, cpt);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hexa(c, (unsigned int)nb, cpt);
	else if (c == 'p')
	{
		if (nb == 0)
			ft_putstr_cpt("(nil)", cpt);
		else
			ft_putnbr_hexa(c, (long int)nb, cpt);
	}
	(*i) = (*i) + 1;
}

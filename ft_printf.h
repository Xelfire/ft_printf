/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdussoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:42:54 by tdussoye          #+#    #+#             */
/*   Updated: 2022/12/27 18:42:57 by tdussoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putnbr_hexa(char c, long long nb, int *cpt);
void	ft_putnbr_cpt(long long nb, int *cpt);
void	ft_putstr_cpt(const char *s, int *cpt);
void	ft_putchar_cpt(char c, int *cpt);
int		ft_printf(const char *str, ...);
void	ft_putstr_cpti(const char *s, int *i, int *cpt);
void	ft_choix(char c, long int nb, int *i, int *cpt);

#endif

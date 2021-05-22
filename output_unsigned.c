/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:03:09 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/17 06:15:20 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(va_list *ap, t_ftype *ftype)
{
	unsigned long long	n;

	n = va_arg(*ap, unsigned int);
	ft_check_unsigned(ftype, n);
	if (ftype->flag[0] == 0 && ftype->flag[1] == 0)
		ft_write_space(' ', ftype->field);
	if (ftype->flag[0] == 1 && ftype->flag[1] == 0)
		ft_write_space('0', ftype->accu + ftype->field);
	else
		ft_write_space('0', ftype->accu);
	if (n)
		ft_write_intux(n, *ftype);
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}

void	ft_check_unsigned(t_ftype *ftype, unsigned long long n)
{
	if (!(ftype->accu == -1))
		ftype->flag[0] = 0;
	ftype->output_len = ch_unsigned_digit(n, ftype);
	if (ftype->accu <= ftype->output_len)
		ftype->accu = (n == 0 && ftype->accu);
	else
		ftype->accu -= ftype->output_len;
	if (ftype->spec == 2 && n != 0)
		ftype->output_len += ftype->accu + 2;
	else
		ftype->output_len += ftype->accu;
	if (ftype->field <= ftype->output_len)
		ftype->field = 0;
	else
		ftype->field -= ftype->output_len;
}

int		ch_unsigned_digit(unsigned long long n, t_ftype *ftype)
{
	int					i;

	i = 0;
	if (ftype->spec == 5)
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= 16;
			i++;
		}
	}
	return (i);
}

void	ft_write_change(unsigned long long n, char *base, unsigned int size)
{
	char				c;

	if (n >= size)
		ft_write_change(n / size, base, size);
	c = base[n % size];
	write(1, &c, 1);
}

void	ft_write_intux(unsigned long long n, t_ftype ftype)
{
	if (ftype.spec == 2 || ftype.spec == 6)
		ft_write_change(n, "0123456789abcdef", 16);
	else if (ftype.spec == 7)
		ft_write_change(n, "0123456789ABCDEF", 16);
	else
		ft_write_change(n, "0123456789", 10);
}

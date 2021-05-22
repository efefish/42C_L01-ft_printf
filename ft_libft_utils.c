/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:58:10 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/17 05:15:47 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_strchr2(const char *s, char c)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_printf_strchr9(const char *s, char c)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

void	ft_write_space(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
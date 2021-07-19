/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:48:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/19 12:56:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stddef.h>

#define UCHAR unsigned char

static int	ft_isspace(int c)
{
	return (((UCHAR)c >= '\t' && (UCHAR)c <= '\r') || (UCHAR)c == ' ');
}

static int	ft_isdigit(int c)
{
	return ((unsigned char)c >= '0' && (unsigned char)c <= '9');
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0 && n / 10 == 0)
	{
		c = '-';
		write(fd, &c, sizeof(char));
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0)
	{
		c = (n % 10) * -1 + '0';
		write(fd, &c, sizeof(char));
	}
	else
	{
		c = n % 10 + '0';
		write(fd, &c, sizeof(char));
	}
}

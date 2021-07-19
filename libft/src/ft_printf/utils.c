/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 22:59:57 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "flags.h"
#include "libft.h"

void	add_padding(t_pinfo *info, int len, char c)
{
	while (len++ < info->width)
		info->count += info->ft_putc(c);
}

void	ft_putstr(char *str, t_pinfo *info)
{
	while (*str)
		info->count += info->ft_putc(*str++);
}

char	get_pad_char(t_pinfo *info)
{
	if (info->flags & F_ZEROPAD)
		return ('0');
	return (' ');
}

int	to_int(const char **fmt)
{
	int	width;

	width = 0;
	while (ft_isdigit(**fmt))
		width = width * 10 + (*((*fmt)++) - '0');
	return (width);
}

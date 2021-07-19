/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:07:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/19 11:27:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_printf.h"
#include "libft.h"
#include <unistd.h>

static int	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
	return (sizeof(char));
}

static void	get_wchar_info(wint_t c, t_wchar_info *wchar_info)
{
	if (c > 0xFFFF)
	{
		wchar_info->header = 0xF0;
		wchar_info->shift = 18;
		wchar_info->size = 4;
	}
	else if (c > 0x7FF)
	{
		wchar_info->header = 0xE0;
		wchar_info->shift = 12;
		wchar_info->size = 3;
	}
	else if (c > 0x7F)
	{
		wchar_info->header = 0xC0;
		wchar_info->shift = 6;
		wchar_info->size = 2;
	}
	else
	{
		wchar_info->header = 0x00;
		wchar_info->shift = -1;
		wchar_info->size = 1;
	}
}

static unsigned int	get_wchar_mask(wint_t c)
{
	if (c > 0xFFFF)
		return (0x07);
	if (c > 0x7FF)
		return (0x0F);
	if (c > 0x7F)
		return (0x1F);
	return (0x00);
}

static int	ft_putwchar(wint_t c)
{
	t_wchar_info	info;

	get_wchar_info(c, &info);
	info.mask = get_wchar_mask(c);
	if (info.size == 1)
		ft_putchar((char)c);
	else
	{
		ft_putchar(info.header | (((c >> info.shift) & info.mask)));
		info.shift -= 6;
	}
	while (info.shift >= 0)
	{
		ft_putchar(0x80 | ((c >> info.shift) & 0x3F));
		info.shift -= 6;
	}
	return (info.size);
}

int	ft_printf(const char *format, ...)
{
	t_pinfo	info;
	int		result;

	if (!format)
		return (-1);
	info = (t_pinfo){};
	va_start(info.va, format);
	info.ft_putc = ft_putchar;
	info.ft_putwc = ft_putwchar;
	info.count = 0;
	result = do_printf(format, &info);
	va_end(info.va);
	return (result);
}

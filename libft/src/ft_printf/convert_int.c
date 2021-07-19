/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:33:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 02:01:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "utils.h"
#include <stdlib.h>

static long long	get_number(t_pinfo *info)
{
	if (info->flags & F_LONG_LONG)
		return ((long long)va_arg(info->va, long long));
	else if (info->flags & F_LONG)
		return ((long)va_arg(info->va, long));
	else if (info->flags & F_HALF_HALF)
		return ((char)va_arg(info->va, int));
	else if (info->flags & F_HALF)
		return ((short)va_arg(info->va, int));
	else
		return ((int)va_arg(info->va, int));
}

static char	*get_prefix(t_pinfo *info, long long nb)
{
	if (nb < 0)
		return ("-");
	else if (info->flags & F_PLUS)
		return ("+");
	else if (info->flags & F_SPACE)
		return (" ");
	else
		return (NULL);
}

static char	*convert_to_str(long long nb, t_pinfo *info)
{
	if (info->flags & F_LONG_LONG && nb < 0)
		return (ft_ulltoa((unsigned long long)(0 - nb)));
	else if (info->flags & F_LONG_LONG)
		return (ft_ulltoa((unsigned long long)(nb)));
	else if (info->flags & F_LONG && (long)nb < 0)
		return (ft_ultoa((unsigned long)(0 - (long)nb)));
	else if (info->flags & F_LONG)
		return (ft_ultoa((unsigned long)((long)nb)));
	else if (info->flags & F_HALF_HALF && (char)nb < 0)
		return (ft_utoa((unsigned int)(0 - (char)nb)));
	else if (info->flags & F_HALF_HALF)
		return (ft_utoa((unsigned int)((char)nb)));
	else if (info->flags & F_HALF && (short)nb < 0)
		return (ft_utoa((unsigned int)(0 - (short)nb)));
	else if (info->flags & F_HALF)
		return (ft_utoa((unsigned int)((short)nb)));
	else if ((int)nb < 0)
		return (ft_utoa((unsigned int)(0 - (int)nb)));
	else
		return (ft_utoa((unsigned int)((int)nb)));
}

static void	print_number(t_pinfo *info, char *str, char *prefix, char pad_char)
{
	if (prefix)
		info->width--;
	if (prefix && pad_char == '0')
		ft_putstr(prefix, info);
	if (!(info->flags & F_LEFTALIGN))
		add_num_padding(info, pad_char);
	if (prefix && pad_char == ' ')
		ft_putstr(prefix, info);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0)
			info->count += info->ft_putc('0');
	ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_int(t_pinfo *info)
{
	long long	nb;
	char		pad_char;
	char		*str;
	char		*prefix;
	bool		precision_is_0;

	nb = get_number(info);
	if (info->flags & F_PRECISION)
		info->flags &= ~F_ZEROPAD;
	pad_char = get_pad_char(info);
	prefix = get_prefix(info, nb);
	precision_is_0 = (info->flags & F_PRECISION) && (info->precision == 0);
	if (nb == 0 && precision_is_0)
	{
		add_num_padding_sign(info, ' ', prefix);
		return (true);
	}
	str = convert_to_str(nb, info);
	if (!str)
		return (false);
	calculate_padding(info, str);
	print_number(info, str, prefix, pad_char);
	free(str);
	return (true);
}

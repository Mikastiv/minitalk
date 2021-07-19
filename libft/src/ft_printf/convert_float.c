/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:24:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 02:01:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "flags.h"
#include "libft.h"
#include "utils.h"
#include "utils.h"
#include <stdlib.h>
#include <limits.h>
#include <float.h>

static bool	is_special(double nb)
{
	if (nb != nb || nb < -DBL_MAX || nb > DBL_MAX)
		return (true);
	return (false);
}

static char	*get_prefix(t_pinfo *info, double nb)
{
	if (nb < 0.0)
		return ("-");
	else if (info->flags & F_PLUS)
		return ("+");
	else if (info->flags & F_SPACE)
		return (" ");
	else
		return (NULL);
}

static void	calculate_padding_f(t_pinfo *info, char *str)
{
	int	len;

	len = ft_strnlen(str, INT_MAX);
	info->width -= len;
	if (info->precision == 0 && info->flags & F_HASH)
		info->width--;
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
	ft_putstr(str, info);
	if (info->precision == 0 && info->flags & F_HASH)
		ft_putstr(".", info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_float(t_pinfo *info)
{
	double	nb;
	char	pad_char;
	char	*str;
	char	*prefix;

	nb = va_arg(info->va, double);
	pad_char = get_pad_char(info);
	if (is_special(nb))
		pad_char = ' ';
	prefix = get_prefix(info, nb);
	if (!(info->flags & F_PRECISION))
		info->precision = 6;
	if (nb < 0.0)
		nb = 0 - nb;
	str = ft_ftoa(nb, info->precision);
	if (!str)
		return (false);
	calculate_padding_f(info, str);
	print_number(info, str, prefix, pad_char);
	free(str);
	return (true);
}

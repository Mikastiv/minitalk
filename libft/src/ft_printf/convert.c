/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 01:57:22 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

bool	convert(const char **fmt, t_pinfo *info)
{
	if (**fmt == 'c' && ++(*fmt))
		return (convert_char(info, va_arg(info->va, unsigned int)));
	else if (**fmt == 's' && ++(*fmt))
		return (convert_str(info));
	else if (**fmt == 'p' && ++(*fmt))
		return (convert_ptr(info));
	else if ((**fmt == 'd' || **fmt == 'i') && ++(*fmt))
		return (convert_int(info));
	else if (**fmt == 'u' && ++(*fmt))
		return (convert_uint(info, "0123456789", ""));
	else if (**fmt == 'x' && ++(*fmt))
		return (convert_uint(info, "0123456789abcdef", "0x"));
	else if (**fmt == 'X' && ++(*fmt))
		return (convert_uint(info, "0123456789ABCDEF", "0X"));
	else if (**fmt == 'b' && ++(*fmt))
		return (convert_uint(info, "01", "0b"));
	else if (**fmt == '%' && ++(*fmt))
		return (convert_percent(info));
	else if (**fmt == 'n' && ++(*fmt))
		return (convert_n(info));
	else if (**fmt == 'f' && ++(*fmt))
		return (convert_float(info));
	else
		return (convert_char(info, *((*fmt)++)));
}

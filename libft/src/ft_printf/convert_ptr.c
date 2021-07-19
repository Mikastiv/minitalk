/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:57:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 02:01:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"
#include "utils.h"
#include "flags.h"
#include "utils.h"
#include <stdlib.h>

static void	print_number(t_pinfo *info, char *str, char pad_char)
{
	if (!(info->flags & F_LEFTALIGN) && pad_char == ' ')
		add_num_padding(info, pad_char);
	ft_putstr("0x", info);
	if (!(info->flags & F_LEFTALIGN) && pad_char == '0')
		add_num_padding(info, pad_char);
	if (info->flags & F_PRECISION)
		while (info->precision && info->precision-- > 0)
			info->count += info->ft_putc('0');
	if (!(info->flags & F_PRECISION && info->precision <= 0
			&& ft_strncmp(str, "0", 2) == 0))
		ft_putstr(str, info);
	if (info->flags & F_LEFTALIGN)
		add_num_padding(info, pad_char);
}

bool	convert_ptr(t_pinfo *info)
{
	void	*ptr;
	char	*str;
	char	pad_char;

	ptr = va_arg(info->va, void *);
	str = ft_ptoa_base(ptr, "0123456789abcdef");
	if (!str)
		return (false);
	info->width -= 2;
	pad_char = get_pad_char(info);
	calculate_padding(info, str);
	if (info->flags & F_PRECISION && info->precision <= 0
		&& ft_strncmp(str, "0", 2) == 0)
		info->width++;
	print_number(info, str, pad_char);
	free(str);
	return (true);
}

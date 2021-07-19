/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:26:13 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 01:58:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "flags.h"
#include "utils.h"
#include "libft.h"

bool	convert_char(t_pinfo *info, wint_t c)
{
	int		char_width;
	char	pad_char;

	pad_char = get_pad_char(info);
	if (info->flags & F_LONG)
		char_width = ft_wchar_size(c);
	else
		char_width = sizeof(char);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, char_width, pad_char);
	if (info->flags & F_LONG)
		info->count += info->ft_putwc(c);
	else
		info->count += info->ft_putc((char)c);
	if (info->flags & F_LEFTALIGN)
		add_padding(info, char_width, pad_char);
	return (true);
}

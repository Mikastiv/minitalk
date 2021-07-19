/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:16:52 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 01:58:58 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "flags.h"
#include "utils.h"

bool	convert_percent(t_pinfo *info)
{
	int		char_width;
	char	pad_char;

	char_width = sizeof(char);
	pad_char = get_pad_char(info);
	if (!(info->flags & F_LEFTALIGN))
		add_padding(info, char_width, pad_char);
	info->count += info->ft_putc('%');
	if (info->flags & F_LEFTALIGN)
		add_padding(info, char_width, pad_char);
	return (true);
}

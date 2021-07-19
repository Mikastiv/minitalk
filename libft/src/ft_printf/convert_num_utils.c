/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:51:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 02:03:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "flags.h"
#include "libft.h"
#include <limits.h>

void	add_num_padding(t_pinfo *info, char c)
{
	while (info->width-- > 0)
		info->count += info->ft_putc(c);
}

void	add_num_padding_sign(t_pinfo *info, char c, char *prefix)
{
	if (prefix)
		info->width--;
	if (info->flags & F_LEFTALIGN && prefix)
		info->count += info->ft_putc(*prefix);
	while (info->width-- > 0)
		info->count += info->ft_putc(c);
	if (!(info->flags & F_LEFTALIGN) && prefix)
		info->count += info->ft_putc(*prefix);
}

void	calculate_padding(t_pinfo *info, char *str)
{
	int	len;

	len = ft_strnlen(str, INT_MAX);
	info->width -= len;
	info->precision -= len;
	if (info->flags & F_PRECISION && info->precision > 0)
		info->width -= info->precision;
}

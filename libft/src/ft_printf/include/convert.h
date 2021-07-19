/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:10:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/09 12:06:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "do_printf.h"
# include <stdbool.h>
# include <wchar.h>

typedef struct s_floatinfo
{
	bool			negative;
	unsigned long	whole;
	unsigned long	frac;
	double			diff;
	double			tmp;
	size_t			zero_pad;
	size_t			whole_len;
	size_t			frac_len;
	size_t			str_len;
}	t_floatinfo;

bool	convert(const char **fmt, t_pinfo *info);
bool	convert_char(t_pinfo *info, wint_t c);
bool	convert_float(t_pinfo *info);
bool	convert_int(t_pinfo *info);
bool	convert_n(t_pinfo *info);
bool	convert_percent(t_pinfo *info);
bool	convert_ptr(t_pinfo *info);
bool	convert_str(t_pinfo *info);
bool	convert_uint(t_pinfo *info, char *base, char *prefix);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:14:11 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/17 14:47:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = sizeof(char) * 8;
	while (bit)
	{
		--bit;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_string(char *str, pid_t pid)
{
	while (*str)
		send_char(*str++, pid);
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc < 3)
	{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(" [server pid] [message]", STDERR_FILENO);
		return (0);
	}
	spid = ft_atoi(argv[1]);
	send_string(argv[2], spid);
}

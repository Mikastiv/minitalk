/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:14:08 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/19 12:53:31 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

void	handler(int signo)
{
	static char	c;
	static int	bit = 0;

	if (bit == 0)
	{
		c = 0;
		bit = sizeof(char) * 8;
	}
	--bit;
	if (signo == SIGUSR1)
		c |= (1 << bit);
	if (bit == 0)
	{
		write(STDOUT_FILENO, &c, 1);
		if (c == 0)
			write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1)
	{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (0);
	}
	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (true)
		;
}

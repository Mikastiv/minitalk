/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:36 by laube             #+#    #+#             */
/*   Updated: 2021/08/18 14:52:25 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include "../libft/libft.h"

typedef struct s_parse
{
	int	bin;
	char	**env;
	char	*cmd;
	char	**cmd_args; // Needs to start with bin name, and be NULL terminated
} t_parse;

void	ft_terminate(int errno)
{
	char	*err_str;

	if (errno != 0)
		err_str = strerror(errno);
	else
		err_str = "There has been an undefined error";
	printf("%s\n", err_str);
	exit(0);
}

char	*validate_path(char *path, char *cmd)
{
	char	**paths;
	char	*tmp_path;
	char	*tentative_binpath;
	struct stat	buff;

	path = ft_strchr(path, '=') + 1;
	paths = ft_split(path, ':');
	while (*paths)
	{
		tmp_path = ft_strjoin(*paths, "/");
		tentative_binpath = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (stat(tentative_binpath, &buff) == 0)
			return (tentative_binpath);
		free(tentative_binpath);
		paths++;
	}
	return (NULL);
}

/*	Finds the PATH variable,
	then returns the full binary path of the binary */
char	*get_bin_path(char **envp, char *cmd)
{
	char	*path;

	while (*envp)
	{
		path = ft_strnstr(*envp, "PATH=", 5);
		if (path != NULL)
			return (validate_path(path, cmd));
		envp++;
	}
	return (NULL);
}

/*	Executes the binary entered as cmd */
int	ft_binary(t_parse *parse)
{
	char	*bin_path;
	pid_t	pid;

	bin_path = get_bin_path(parse->env, parse->cmd);
	if (bin_path == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
		ft_terminate(errno);
	if (pid == 0)
	{
		execve(bin_path, parse->cmd_args, parse->env);
		if (execve == -1)
			ft_terminate(errno);
	}
	wait(0);
	return (0);
}

void	ft_echo(t_parse *parse)
{
	int	i;
	int	nl;

	i = 0;
	nl = 1;
	if (ft_strnstr(parse->cmd_args)[i], '-n', 2)
	{
		nl = 0;
		i++;
	}
	while ((parse->cmd_args)[i])
	{
		printf("%s", (parse->cmd_args));
		i++;
		if ((parse->cmd_args)[i])
			ft_putchar(' ');
	}
	if (nl)
		ft_putchar('\n');
}

void	ft_cd(t_parse *parse)
{
	
}

int	execution_control(t_parse *parse)
{
	if (parse->bin == 1)
		ft_binary(parse);
	else if (ft_strnstr(parse->cmd, "echo", 4))
	{
		ft_echo(parse);
	}
	else if (ft_strnstr(parse->cmd, "cd", 2))
	{
		ft_cd(parse);
	}
	else if (ft_strnstr(parse->cmd, "pwd", 3))
	{
		ft_pwd(parse);
	}
	else if (ft_strnstr(parse->cmd, "export", 6))
	{
		ft_export(parse);
	}
	else if (ft_strnstr(parse->cmd, "unset", 5))
	{
		ft_unset(parse);
	}
	else if (ft_strnstr(parse->cmd, "env", 3))
	{
		ft_env(parse);
	}
	else if (ft_strnstr(parse->cmd, "exit", 4))
	{
		ft_exit(parse);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_parse	*parse;
	char *test_args[3] = {"ls", "-l", NULL};

	parse = malloc(sizeof(*parse));
	parse->bin = 1;
	parse->env = env;
	parse->cmd = "ls";
	parse->cmd_args = test_args;
	// This function will take whatever Michael gives it after parsing
	execution_control(parse);

	return (0);
}
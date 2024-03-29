/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 05:26:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/25 06:02:45 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

void	parent(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	exec(argv[3], env);
}

void	child(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 1);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	exec(argv[2], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int	pipefd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (!pid)
			child(argv, pipefd, env);
		parent(argv, pipefd, env);
	}
	else
	{
		exit_handler(1);
	}

	return (0);
}

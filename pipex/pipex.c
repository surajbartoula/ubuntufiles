/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 05:26:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/31 10:41:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	execute(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;
	int	i;

	i = -1;
	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		ft_free_tab(s_cmd);
		error();
	}
	i = -1;
	if (execve(path, s_cmd, env) == -1)
	{
		ft_free_tab(s_cmd);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		exit(0);
	}
}

void	parent_proc(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	if (fd == -1)
		error();
	dup2(pipefd[0], 0);
	dup2(fd, 1);
	close(pipefd[1]);
	execute(argv[3], env);
}

void	child_proc(char **argv, int *pipefd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	if (fd == -1)
		error();
	dup2(pipefd[1], 1);
	dup2(fd, 1);
	close(pipefd[0]);
	execute(argv[2], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int	pipefd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_proc(argv, pipefd, env);
		parent_proc(argv, pipefd, env);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguements\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}

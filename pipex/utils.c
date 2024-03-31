/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 06:03:18 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/31 10:28:23 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>

void	error()
{
	perror("Error");
	exit(-1);
}

int	open_file(char *file, int file_d)
{
	int	file_no;
	
	if (file_d == 0)
		file_no = open(file, O_RDONLY, 0777);
	if (file_d == 1)
		file_no = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_no == -1)
		exit(0);
	return (file_no);
}

void	ft_free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_path(char *cmd, char **env)
{
	int	i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	allpath = ft_split(env[i] + 5, ':');
	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	ft_free_tab(allpath);
	return (0);
}

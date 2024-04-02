/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 05:33:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/02 18:30:21 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

void		error(void);
void		ft_free_tab(char **tab);
void		execute(char *cmd, char **env);
void		child_proc(char **argv, int *pipefd, char **env);
void		parent_proc(char **argv, int *pipefd, char **env);
char		*get_path(char *cmd, char **env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:16:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/19 16:21:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main( void )
{
	pid_t	pid;

	pid = fork();
	printf("Parent process PID is %d, child's PID is %d.\n",
		getpid(), pid);
	return (0);
}

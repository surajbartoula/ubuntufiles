/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkadvance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/03/19 16:48:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main( void )
{
	pid_t	pid;

	pid = 9;
	printf(">>>>>>>>>\n");
	printf("My PID before fork %d.\n", getpid());
	pid = fork();
	printf("---------\n");
	printf("My PID after fork %d.\n", getpid());
	if (pid < 0)
	{
		fprintf(stderr, "Fork2 failed.\n");
		return (1);
	}
	else if (pid == 0)
	{
		printf("C process PID is %d c PID is %d\n", getpid(), pid);
	}
	else
	{
		printf("PID %d & child PID %d\n", getpid(), pid);
	}
	return (0);
}

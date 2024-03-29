#include <unistd.h>
#include <stdio.h>

int main()
{
	char *const args[] = {"ls", NULL};
	char *const envp[] = {NULL};

	execve("/usr/bin/ls", args, envp);
	perror("execve");
	return (1);
}

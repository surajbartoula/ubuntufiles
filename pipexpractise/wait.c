#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int id = fork();
	int n;

	if (id == 0)
		n = 1;
	else
		n = 6;
	int i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

// declare array
char *array[512];

// split input on new lines
void stringSplit(char *input)
{
	int i = 0;
	char *token = strtok(input, "\n ");
	while (token != NULL)
	{
		// add tokens into the array
		array[i++] = token;
		token = strtok(NULL, "\n ");
	}
}

/* Execute a command */
void execute()
{
	int success = 1, ended = 1;

	// Create a new process
	int pid = fork();
	if (pid != 0)
	{
		//the process has not yet been completed
		wait(NULL);
		if (success)
		{
			printf("Terminou comando lista com código 1\n");
			printf("%%");
		}
	}
	else
	{
		// execute the command, if -1 the command was unrecognized by the system
		if (execv(array[0], array) == -1)
		{
			// Display error message
			success = 0;
			printf("Terminou comando lista com código 0\n");
			printf("%%");
			exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	char *input = NULL;
	size_t capline = 0;

	// prints the first '%'
	printf("%%");

	while (1)
	{
		// Read the user input
		getline(&input, &capline, stdin);
		// allow to continue when the user didn't right anything in the current line
		if (strcmp(input, "\n") == 0)
		{
			printf("%%");
			continue;
		}

		// split input on new lines
		stringSplit(input);

		// validate if command equals to termina
		if (strcmp(array[0], "termina") == 0)
		{
			return 0;
		}
		else
		{
			execute();
		}
	}
}
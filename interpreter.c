#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

// declare array
char *array[512];

// divide input line into tokens
void makeTokens(char *input)
{
	int i = 0;
	char *token = strtok(input, "\n");
	while (token != NULL)
	{
		// Add tokens into the array
		array[i++] = token;
		token = strtok(NULL, "\n");
	}
	array[i] = NULL;
}

/* Execute a command */
void execute()
{
	int pid = fork(); // Create a new process
	if (pid != 0)
	{
		// already has a process, wait for it to end
		wait(NULL);
	}
	else
	{
		// execute the command, if -1 the command was unrecognized by the system
		if (execv(array[0], array) == -1)
		{
			// Display error message
			perror("Unrecognized command");
		}
	}
}

int main()
{
	char *input = NULL;
	size_t capline = 0;

	while (1)
	{
		// Read the user input
		printf("%%");
		getline(&input, &capline, stdin);
		// allow to continue when the user didn't right anything in the current line
		if(strcmp(input,"\n")==0){
			continue;
		}

		// Divide line into tokens
		makeTokens(input);
		execute();
	}
}
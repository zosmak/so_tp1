/*
 * Sanzhar Zholdiyarov
 */
/* Purpose: Simple command line interpreter 
  * Usage info: To run a command user need to type any command with/without argument into the prompt and then press 'enter'
  * Other info: This program use execvp() function to execute a command. This gives opportunity for user to not including a path(example: /bin/)
  * Additional features: print out errors, check if input is empty, check if input is 'q'
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>   // Definition for fork() and execve()
#include <errno.h>	// Definition for "error handling"
#include <sys/wait.h> // Definition for wait()

/* Declarations for getline() */
char *input = NULL;
size_t capline = 0; // Capacity

/* Declaration for strtok() */
int i;
char *token;
char *array[512];

//Divide input line into tokens
void makeTokens(char *input)
{
	i = 0;
	token = strtok(input, "\n");
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
		// already has a process, wait for it 
		wait(NULL); 
	}
	else
	{
		// execute the command, if -1 the command was unrecognized by the system
		if (execvp(array[0], array) == -1)
		{
			// Display error message
			perror("Unrecognized command");
		}
	}
}

int main()
{
	while (1)
	{
		// Read the user input
		getline(&input, &capline, stdin);

		// Divide line into tokens
		makeTokens(input);
		
		// validate if the first char is a '%', if yes execute the command
		if (strcmp(array[0], "%") == 0)
		{
			execute();
		}
	}
}
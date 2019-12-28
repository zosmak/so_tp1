#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <sys/wait.h>

	/* Execute a command */
   /*void execute(){
	   int pid = fork(); // Create a new process
				if (pid != 0) { // If not successfully completed
					int s;
					waitpid(-1, &s, 0); // Wait for process termination
			} else {
					if(execvp(array[0], array) == -1){ // If returned -1 => something went wrong! If not then command successfully completed
					perror("Wrong command"); // Display error message
					exit(errno);
				}				
			}<
   }
   */
   	char *array[512]; 

	
	int main(){
		char *input = NULL;
		size_t capline = 0;
		
		while(1){
			std::getline(&input, &capline, stdin); // Read the user input
			/* Check if input is empty */
				if(strcmp(input,"\n")==0){
					perror("Please type in a command " );
					continue;
				}
			
			//makeTokens(input); // Divide line into tokens 

            /* Check if input is "q", if yes then exit shell */
			if (strcmp(array[0], "q") == 0) {
				printf("SYSTEM : Shell is exit\n");
				return 0;
			}
	}
	
	
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	// initialize variables
	int file;
	char str[100];
	
	// reads and prints the text in it
	file = open(argv[1], O_RDONLY);
	if(file == -1){
		perror("Error reading the file");
	} else {
		read(file, str, sizeof(str));
		write(1, str, sizeof(str));
	}
	close(file);
	getchar();
}

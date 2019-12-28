#include <stdio.h>

int main(int argc, char* argv[]){
	// try to delete the file, sends an error if fails
	if (remove(argv[1]) == 0)
		printf("File deleted successfully"); 
	else
		perror("Error deleting the file");
}

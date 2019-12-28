#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
//#include <pwd.h>

int main(int argc, char* argv[]){
	// initialize variables
	struct stat fileStat;
	
	if(stat(argv[1], &fileStat) < 0){
		perror("Error reading the file");
		return 1;
	} else {
		// prints the file information
		// todo: ver melhor o pwd em linux
		printf("File information: %s\n", argv[1]);
		printf("- Size: %d bytes\n", fileStat.st_size);
		printf("- Owner: %d \n",fileStat.st_uid);
		printf("- Created at: %s",ctime(&fileStat.st_ctime));
		printf("- Modificated at: %s",ctime(&fileStat.st_mtime));
		printf("File type:\n");
		printf("\t- Directory: %d \n",fileStat.st_nlink);
		printf("\t- Links: %d \n",fileStat.st_nlink);
		printf("\t- i-node: %d \n",fileStat.st_ino);
	}
}

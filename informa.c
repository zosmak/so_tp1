#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
	// initialize variables
	struct stat fileStat;

	if (stat(argv[1], &fileStat) < 0)
	{
		perror("Error reading the file");
		return 1;
	}
	else
	{
		// prints the file information
		// todo: ver melhor o pwd em linux
		printf("File information: %s\n", argv[1]);
		printf("- Size: %lld bytes\n", fileStat.st_size);
		struct passwd *pw = getpwuid(fileStat.st_uid);
		if (pw != 0)
			printf("- Owner: %s \n", pw->pw_name);
		printf("- Created at: %s", ctime(&fileStat.st_ctime));
		printf("- Modificated at: %s", ctime(&fileStat.st_mtime));
		printf("File type:\n");
		char *path = realpath(argv[1], NULL);
		printf("\t- Directory: %s \n", path);
		printf("\t- Links: %d \n", fileStat.st_nlink);
		printf("\t- i-node: %llu \n", fileStat.st_ino);
	}
}

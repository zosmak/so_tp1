#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	// initialize variables
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir(argv[1])) != NULL)
	{
		// print all the files and directories within directory
		while ((ent = readdir(dir)) != NULL)
		{
			printf("%s\n", ent->d_name);
		}
		closedir(dir);
		return 1;
	}
	else
	{
		perror("Error reading the path");
		return 0;
	}
}

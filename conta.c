#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    // initialize variables
    int file;
    char str[999];
    int count = 0;
    char c;
    int size_of_string;

    file = open(argv[1], O_RDONLY);
    if (file == -1)
    {
        perror("Erro ao ler ficheiro");
        return 0;
    }
    else
    {
        read(file, str, sizeof(str));

        size_of_string = sizeof(str);
        for (int i = 0; i < size_of_string; ++i)
        {
            if (str[i] == '\n')
            {
                count++;
            }
        }
    }
    printf("O ficheiro %s tem %d linhas\n ", argv[1], count);
    close(file);

    return 1;
}

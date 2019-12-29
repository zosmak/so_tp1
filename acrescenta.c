#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // initialize variables
    int file;
    int file2;
    int leng;
    char str[100];

    file2 = open(argv[2], O_RDONLY);
    if (file2 == -1)
    {
        perror("Erro ao ler o segundo ficheiro");
        close(file2);
        return 0;
    }
    else
    {
        leng = read(file2, str, sizeof(str));
    }

    file = open(argv[1], O_RDWR | O_APPEND);
    if (file == -1)
    {
        perror("Erro ao ler o primeiro ficheiro");
        close(file);
        close(file2);
        return 0;
    }
    else
    {
        write(file, str, leng);
        close(file);
        close(file2);
        return 1;
    }
}

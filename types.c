#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // Check if there are enough command-line arguments
    if (argc < 2) {
        printf("usage: path1 [path2 ...]\n");
        return 1;
    }
    
    // Iterate through each command-line argument
    for (int i = 1; i < argc; i++) {
        struct stat fileStat;

        // Check if the path is accessible
        if (stat(argv[i], &fileStat) != 0) {
            printf("%s: path error\n", argv[i]);
            continue;
        }

        // Check the file type using st_mode field
        if (S_ISREG(fileStat.st_mode))
            printf("%s: regular file\n", argv[i]);
        else if (S_ISDIR(fileStat.st_mode))
            printf("%s: directory\n", argv[i]);
        else if (S_ISCHR(fileStat.st_mode))
            printf("%s: character special file\n", argv[i]);
        else if (S_ISBLK(fileStat.st_mode))
            printf("%s: block special file\n", argv[i]);
        else if (S_ISFIFO(fileStat.st_mode))
            printf("%s: FIFO (named pipe)\n", argv[i]);
        else if (S_ISLNK(fileStat.st_mode))
            printf("%s: symbolic link\n", argv[i]);
        else if (S_ISSOCK(fileStat.st_mode))
            printf("%s: socket\n", argv[i]);
        else
            printf("%s: unknown file type\n", argv[i]);
    }
    return 0;
}

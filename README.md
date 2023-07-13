# Quiz 3.2.b: file types

Write a C program that prints the type of file for each path provided as command-line argument.

The following POSIX macros are defined to check the file type using the st_mode field:
```
S_ISREG(m)
is it a regular file?

S_ISDIR(m)
directory?

S_ISCHR(m)
character device?

S_ISBLK(m)
block device?

S_ISFIFO(m)
FIFO (named pipe)?

S_ISLNK(m)
symbolic link? (Not in POSIX.1-1996.)

S_ISSOCK(m)
socket? (Not in POSIX.1-1996.)
```

## Important notes: 
1. If the path is not accessible, print the message `path error`.
1. Refer to the sample output [sample_output.txt](sample_output.txt).
1. Usage: `./types path1 [path2 ...]`
1. Your program will be manually tested for correctness with additional test cases, including different paths.
1. Your program should compile with no errors or warnings.

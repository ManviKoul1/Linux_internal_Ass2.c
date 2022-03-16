//5.Write a program parent process wait untill ,while child process open a file and read file
//data into empty buffer.

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE * fptr;
    fptr = fopen(argv[1],"r");
    char str1;

    int pipefds[2];
    char buffer[5];

    if(pipe(pipefds) == -1)
    {
        perror("PIPE ERROR");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        char singleLine[150];
        close(pipefds[0]);  
        while(!feof(fptr))
        {
            fgets(singleLine, 150, fptr);
            //puts(singleLine);
            write(pipefds[1], singleLine, sizeof(singleLine));
}
        }

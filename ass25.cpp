//1.Test whether the process(exec() system call) that replaces old program data , will inherit
//the fd or not.


 #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("PID of example.c = %d\n", getpid());
    char *args[] = {"Hello", "C", "Programming", NULL};
    execv("./hello", args);
    printf("Back to example.c");
    
    printf("We are in Hello.c\n");
    printf("PID of hello.c = %d\n", getpid());
     printf("PID of example.c = %d\n", getpid());
    pid_t p;
    p = fork();
    if(p==-1)
    {
        printf("There is an error while calling fork()");
    }
    if(p==0)
    {
    printf("We are in the child process\n");
    printf("Calling hello.c from child process\n");
    char *args[] = {"Hello", "C", "Programming", NULL};
    execv("./hello", args);
    }
    else
    {
        printf("We are in the parent process");
    }
    return 0;
}


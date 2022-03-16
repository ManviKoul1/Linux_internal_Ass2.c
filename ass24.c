//4. Write a program child executes(exec()) a new program , while parent waits for
//child task to get complete.


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
int status;
pid_t fork_return;
fork_return = fork();
if (fork_return == 0) /* done by child process */
{
printf("\n I am the child process!");
printf("\n my process id is: %d", getpid());
printf("\n my parent process id is: %d", getppid());
exit(0);
}
else /* done by parent process */
{
wait(&status);
printf("\n I am the parent process");
printf("\n my process id is: %d", getpid());
printf("\n my parent process id is: %d", getppid());
if (WIFEXITED(status))
printf("\n Child returned: %d\n", WEXITSTATUS(status));
}
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    int pid;

    pid = fork();
    if(pid==0){
        // run this as s child process
        printf("this is a child process\n");
        printf("new child Process pid = %d\n", getpid());
        printf("new child Parent Process pid = %d\n", getppid());
        int ret = execl("/usr/bin/vim", "vim","a6.txt", 0);
        // int ret = execl("/bin/ls", "ls", 0);
    } else{
        // run this as a parent process
        wait(0);
        printf("this is a parent process\n");
        printf("parent Process pid = %d\n", getpid());
        printf("child Parent's parent Process pid = %d\n", getppid());
    }
    while(1);
    return 0;
}


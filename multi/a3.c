//Krinal Amipara
//thread id and  pid

#include<pthread.h>
#include<stdio.h>
pthread_t th1;
void *fun(void *arg)
{
pid_t pid;
pthread_t tid;
pid=getpid();
tid=pthread_self();
printf("pid %u \ntid %u \n",(unsigned int)pid,(unsigned int)tid);
return 0;
}

int main(void)
{
int k;
k=pthread_create(&th1,NULL,fun,NULL);
if(k!=0)
printf("can't create thread: %s\n",strerror(k));
while(1);

exit(0);
}

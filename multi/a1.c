//Krinal Amipara
//variable of the process between them.
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int var=5;

void *add(void *arg)
{	sleep(2);
	var= var+10;

	printf("after add=%d\n",var);
}

void *inc(void *arg)
{
	var++;
	printf("after inc=%d\n",var);
}

int main()
{
	pthread_t th1, th2;
	pthread_create(&th1,NULL,add,NULL);
	pthread_create(&th2,NULL,inc,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	printf("globalshar var=%d\n",var);
return 0;
}


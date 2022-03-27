//KrinalAmipara
//mutex 
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int var=5;
pthread_mutex_t my_mutex;
void *add(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	var= var+10;
	pthread_mutex_unlock(&my_mutex);
	printf("after add=%d\n",var);
}

void *inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	var++;
	pthread_mutex_unlock(&my_mutex);
	printf("after inc=%d\n",var);
}

int main()
{
	pthread_t th1,th2;
	pthread_mutex_init(&my_mutex,NULL);
	pthread_create(&th1,NULL,add,NULL);
	pthread_create(&th2,NULL,inc,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);

	printf("var=%d\n",var);
return 0;
}


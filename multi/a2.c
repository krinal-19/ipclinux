//Krinal Amipara
//cancel thread
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *print(void *tid)
{
	printf("\nKrinal Amiapara \n");
	while(1);{}
	}
	int main()
	{
	pthread_t th1;
	int k, t=0;
	printf("creating thread\n");
	k=pthread_create(&th1, NULL, print, NULL);
	printf("thread id: %lu\n",th1);
	sleep(1);
	t=pthread_cancel(th1);
	if(t==0)
	printf("\ncancel thread");
	printf("\nthread id: %lu\n",th1);
	return 0;
}


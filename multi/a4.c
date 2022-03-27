//Krinal Amiapara
//stacksize

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void* fun(void* param){
sleep(2);
return 0;
}
int main(){
pthread_attr_t a; 
pthread_t th1;
void *myst;
size_t mysi; 
int err;
size_t my_stksize = 0x3000000;
void * my_stack;
pthread_attr_init(&a); 
pthread_attr_getstacksize(&a, &mysi); 
pthread_attr_getstackaddr(&a, &myst); 
printf("default addr=%08p default size=%d\n", myst, mysi); 
my_stack = (void*)malloc(my_stksize); 

pthread_attr_setstack(&a, my_stack, my_stksize);
pthread_create(&th1, &a, fun, NULL);
pthread_attr_getstacksize(&a, &mysi); 
pthread_attr_getstackaddr(&a, &myst); 
printf("modified addr=%08x modified size=%ld\n", myst, mysi);
pthread_join(th1, NULL);
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    
    int ret = execl(argv[1], argv[2],argv[3], 0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
    return(0);
}

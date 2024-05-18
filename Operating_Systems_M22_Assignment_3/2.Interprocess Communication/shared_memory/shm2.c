#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<time.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){

    char stringArray[1024];
    char str2[100];

    void *SharedMemory;
    key_t ID = ftok("shmfile",65);
  
    int shmid = shmget(ID,1024,0666);
    
    SharedMemory= shmat(shmid,NULL,0);

    

    while(1){
        printf("Received in P2 :\n");
        printf("%s",(char *)SharedMemory);
        strcpy(stringArray,(char *)SharedMemory);
        int l = strlen(stringArray);
        sprintf(str2,"%c%c",stringArray[l-3],stringArray[l-2]);
        printf("Sent from P2 : %s\n",str2);
        strcpy(SharedMemory,str2);
        if(atoi(str2)==49) break;
        sleep(1);
    }

}

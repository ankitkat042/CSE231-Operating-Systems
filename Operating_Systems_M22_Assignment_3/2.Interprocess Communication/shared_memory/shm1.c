#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
 
#define BIL 1000000000L;


char *createStringArray(int i){
    char characters[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz"};
    char *size= malloc(sizeof(char) *(6 +2));
    for(int i=0;i<6;i++){
        size[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    sprintf(size,"%s%d%d",size,i/10,i%10);
    size[8]='\n';
    size[9]='\0';
    return size;
}

int main(){
    char *s[50];
    for(int i=0;i<50;i++){
        s[i]=createStringArray(i);
        printf("%s\n",s[i]);
    }
    printf("Above are the random strings\n");
    char sendingArray[1024];
    void *SharedMem;
    key_t key = ftok("shmfile",65);
    int ID = shmget(key,1024,0666|IPC_CREAT);
    SharedMem = shmat(ID,NULL,0);

    int currentIndex=0;

    char strread[1024];


    struct timespec before;
    struct timespec after;


    clock_gettime(CLOCK_REALTIME,&before);

    while(1){
        sprintf(sendingArray , "%s%s%s%s%s" , s[currentIndex],s[currentIndex+1],s[currentIndex+2],s[currentIndex+3],s[currentIndex+4]);
        strcpy(SharedMem,sendingArray);
        sleep(1);
        strcpy(strread,(char *)SharedMem);
        currentIndex = atoi(strread);
        printf("Received : %d\n",currentIndex);
        if(currentIndex!=0) currentIndex++;
        if(currentIndex==50) break;

    }

    clock_gettime(CLOCK_REALTIME,&after);
    double ttimee = (after.tv_sec - before.tv_sec) + (double)(after.tv_nsec - before.tv_nsec)/(double)BIL;
    printf("TTime took in total: %lf\n",ttimee);
    return 0;

}

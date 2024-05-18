
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define FIFO_FILE1 "MYFIFO1"
#define FIFO_FILE2 "MYFIFO2"
//get
void READER1(int SEND1, char characterArray[50][11], int j)
{
    int INDEX = j;
    while (j < INDEX + 5)
    {
        read(SEND1, characterArray[j], sizeof(characterArray[j]));
        printf("Sent by 1st Processor off fifo: %s\n", characterArray[j]);
        j++;
    }
}

void main()
{
    struct timespec start, end;
    int SEND1, SEND2;
    char characterArray[50][11] = {{0}};
    char TOTALWORDS[100];
    int i = 0,j=0;

    mkfifo(FIFO_FILE1, 0666);
    mkfifo(FIFO_FILE2, 0666);

    clock_gettime(CLOCK_REALTIME, &start);
    while (i < 50)
    {
        SEND1 = open(FIFO_FILE1, O_RDONLY);
        READER1(SEND1, characterArray, j);
        close(SEND1);
        printf("\n");
        SEND2 = open(FIFO_FILE2, O_WRONLY);
        sprintf(TOTALWORDS, "%d",j+5);
        write(SEND2, TOTALWORDS, sizeof(TOTALWORDS));
        printf("2nd Processor of fifo sends: %s\n", TOTALWORDS);
        close(SEND2);
        printf("\n");
        j = atoi(TOTALWORDS);
        i+=5;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e9;
    time = (time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    printf("Time taken by 2nd Processor of fifo is %f seconds\n", time);
}
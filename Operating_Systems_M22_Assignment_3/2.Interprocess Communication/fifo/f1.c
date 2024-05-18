
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define FIFO_FILE1 "MYFIFO1"
#define FIFO_FILE2 "MYFIFO2"
//send
void file_writer_1(int SEND1, char charaterArray[50][11], int j)
{
    int INDEX = j;
    while (j < INDEX + 5){
        write(SEND1, charaterArray[j], sizeof(charaterArray[j]));
        printf("1st Processor of fifo sends: %s\n", charaterArray[j]);
        j++;
    }
}

void main()
{
    int SEND1, SEND2;
    char TOTALWORDS[100];
    char charaterArray[50][11] = {{0}};
    struct timespec start, end;
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 10; j++)
            charaterArray[i][j] = rand()%26+65;
    for (int i = 0; i < 50; i++)
        printf("%s\n", charaterArray[i]);
    printf("Number of words %d\n", sizeof(charaterArray)/sizeof(charaterArray[0]));
    mkfifo(FIFO_FILE1, 0666);
    mkfifo(FIFO_FILE2, 0666);

    int i = 0,j=0;
    clock_gettime(CLOCK_REALTIME, &start);
    while (i < 50){
        SEND1 = open(FIFO_FILE1, O_WRONLY);
        file_writer_1(SEND1, charaterArray, j);
        close(SEND1);
        printf("\n");
        SEND2 = open(FIFO_FILE2, O_RDONLY);
        read(SEND2, TOTALWORDS, sizeof(TOTALWORDS));
        printf("Sent by 2nd Procssor of fifo: %s\n", TOTALWORDS);
        close(SEND2);
        printf("\n");
        j = atoi(TOTALWORDS);
        i+=5;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double timee;
    timee = (end.tv_sec - start.tv_sec) * 1000000000;
    timee = (timee + (end.tv_nsec - start.tv_nsec))*1e-9;
    printf("Time taken by processor1 is %f seconds\n", timee);
    unlink(FIFO_FILE1);
    unlink(FIFO_FILE2);
    exit(0);
}
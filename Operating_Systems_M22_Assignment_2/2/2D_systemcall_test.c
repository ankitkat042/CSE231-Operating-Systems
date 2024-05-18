#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define sys_twodcopy 451

int main(){
    int row=3, column=3;
    float source[3][3]={{1.1,2.2,3.3},{4.4,5.5,6.6},{7.7,8.8,9.9}}, destination[row][column];

    for(int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            printf("%f ", source[i][j]);
        }
        printf("\n");
    }


    int res = syscall(451, destination, source, row, column);
    
    if(res==-1){
        printf("Error: System call failed\n");
    }
    else{
        printf("copied matrix: \n");
        for(int i=0; i<row; i++) {
            for (int j=0; j<column; j++){
                printf("%f ", destination[i][j]);
            }
            printf("\n");
        }

    }
    
    return res;

}
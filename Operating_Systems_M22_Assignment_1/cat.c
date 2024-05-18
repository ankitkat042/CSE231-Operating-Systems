#include<stdio.h>
#include<string.h> 
#include <errno.h>
#include <stdlib.h>

extern int errno ;

void main(int argc , char *argv[]){
    int i=1,option=0;
    int mk=1;
    if(strcmp(argv[1],"-n")==0){
      i=2;
      option=1;
    }
    else if(strcmp(argv[1],"-E")==0){
      i=2;
      option=2;
    }
    for(;i<argc;i++){
      FILE *file;
      char line[1024];    
      file = fopen(argv[i],"r"); 
      if(file==NULL){
        printf("ERROR: %s\n",strerror(errno));  
        exit(1);
      }
      if(option ==0){
        while(fgets(line,1024,file)!=NULL){
          printf("%s", line);
        }
      }
      else if(option ==1){
        while(fgets(line,1024,file)!=NULL){
          printf("%d %s",mk,line);
          mk++;
        }
      }
      else if(option ==2){
        while(fgets(line,1024,file)!=NULL){
          int len=strlen(line);
          if(line[len-1]=='\n'){
            line[len-1]='$';
            printf("%s\n", line);
          }
          else 
            printf("%s$", line);
        }
      }
      printf("\n");
      fclose(file);
    }
}
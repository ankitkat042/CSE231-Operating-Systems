#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>
#include<string.h> 

extern int errno ;

void help_mkdir(){
    printf("sage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n");
    printf("Mandatory arguments to long options are mandatory for short options too.\n");
    printf("-p, --parents     no error if existing, make parent directories as needed\n--help     display this help and exit\n\n");
}
int main(int argc,char **argv) 
{ 
    int check; 
    if(strcmp(argv[1],"--help")==0){
      help_mkdir();
      exit(0);
    }
    else if(strcmp(argv[1],"-v")==0){
      for(int i=2;i<argc;i++){
      check = mkdir(argv[i],0777); 
       char *token;
       char *token2;
       token=strtok(argv[i],"/");
       while(token!=NULL){
         token2=token;
         token=strtok(NULL,"/");
       }
       if(!check) 
        printf("mkdir: created directory '%s'\n",token2); 
       else { 
        printf("ERROR: %s\n",strerror( errno )); 
       } 
      }
    }
    else 
{
      for(int i=1;i<argc;i++){
      check = mkdir(argv[i],0777); 
      if(check){ 
        printf("ERROR: %s\n",strerror( errno )); 
      } 
      }
    }
}
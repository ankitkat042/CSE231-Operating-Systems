#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<string.h> 
#include <errno.h>

extern int errno ;

void help_rm(){
    printf("Usage: rm [OPTION]... [FILE]...\nRemove (unlink) the FILE(s).\n");
    printf("Mandatory arguments to long options are mandatory for short options too.\n");
    printf("-i    prompt before every removal\n--help     display this help and exit\n\n");
}
int main(int argc,char **argv) { 
    if(strcmp(argv[1],"--help")==0){
      help_rm();
      exit(0);
    }
    else if(strcmp(argv[1],"-i")==0){
      for(int i=2;i<argc;i++){
        printf("rm: remove regular empty file '%s'?y ",argv[i]);
        char chr;
        scanf("%c",&chr);
        if(chr=='y'){
          if (remove(argv[i]) != 0) 
            printf("ERROR: %s\n",strerror( errno ));  
        }
      }
    }
    else {
      for(int i=1;i<argc;i++){
        if (remove(argv[i]) != 0) 
          printf("ERROR: %s\n",strerror( errno ));  
      }
    }
}
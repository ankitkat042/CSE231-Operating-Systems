#include<stdio.h>
#include<time.h>
#include <stdlib.h> 
#include <string.h> 

void help_date(){
    printf("Usage: date [OPTION]... [+FORMAT]\nor:  date [-u|--utc|--universal] [MMDDhhmm[[CC]YY][.ss]]\nDisplay the current time in the given FORMAT, or set the system date.\n");
    printf("Mandatory arguments to long options are mandatory for short options too.\n");
    printf("-u,    --utc, --universal     print or set Coordinated Universal Time (UTC)\n--help     display this help and exit\n\n");
}

int main(int argc,char **argv){
    if(argc==1){
      time_t now=time(&now);
      printf("%s\n", ctime(&now));
    }
    else if(strcmp(argv[1],"-u")==0){
       time_t now = time(&now);  
       struct tm *ptm = gmtime(&now);
       printf("UTC time: %s\n", asctime(ptm));
    }
    else if(strcmp(argv[1],"--help")==0){
       help_date();
    }
    else{
      printf("No such Option\n");
    }
    
    return 0;
}
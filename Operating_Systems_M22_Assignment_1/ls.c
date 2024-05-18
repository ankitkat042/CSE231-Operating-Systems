#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<dirent.h> 
int main(int argc,char **argv){ 
   struct dirent **namelist; 
	int n;
   int flag=0; 
	if(argc < 1){ 
		exit(EXIT_FAILURE); 
	} 
	else if (argc == 1){ 
		n=scandir(".",&namelist,NULL,alphasort); 
	} 
	else if(argc == 2){ 
      if(strcmp(argv[1],"-a")==0){
         flag=1;
         n=scandir(".",&namelist,NULL,alphasort); 
      }
      else if(strcmp(argv[1],"-m")==0){
         flag=2;
         n=scandir(".",&namelist,NULL,alphasort); 
      }
      else if(strcmp(argv[1],"-1")==0){
         flag=3;
         n=scandir(".",&namelist,NULL,alphasort); 
      }
      else 
		   n = scandir(argv[1], &namelist, NULL, alphasort); 
	} 
   else if(argc == 3){
      if(strcmp(argv[1],"-a")==0)
         flag=1;
      else if(strcmp(argv[1],"-m")==0){
         flag=2;}
      else{
         flag=3;
      n = scandir(argv[2], &namelist, NULL, alphasort); }
   }
	if(n < 0) 
	{ 
		perror("No such file or directory"); 
		exit(EXIT_FAILURE); 
	} 
	else{ 
      if(flag==0){
         while (n--){ 
           char* name=namelist[n]->d_name;
           if(name[0]!='.'){
			    printf("%s  ",namelist[n]->d_name); 
			    free(namelist[n]); 
           }
		   } 
		   free(namelist);
         printf("\n");  
      }
      else if(flag==1){
         while (n--){ 
			   printf("%s  ",namelist[n]->d_name); 
			   free(namelist[n]); 
		   } 
		   free(namelist); 
         printf("\n");
      }
      else if(flag==2){
         while (n--){ 
			  char* name=namelist[n]->d_name;
           if(name[0]!='.'){
			    printf("%s, ",namelist[n]->d_name); 
			    free(namelist[n]); 
           }
		   } 
         printf("\n");
		   free(namelist); 
      }
      else{
         while (n--) 
		   { 
			  char* name=namelist[n]->d_name;
           if(name[0]!='.')
           {
			    printf("%s\n",namelist[n]->d_name); 
			    free(namelist[n]); 
           }
		   } 
		   free(namelist); 
      }
	} 
	exit(EXIT_SUCCESS); 
} 

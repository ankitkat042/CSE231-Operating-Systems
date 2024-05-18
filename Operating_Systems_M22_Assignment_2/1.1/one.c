#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <time.h>
#include <sys/resource.h>
void *countA(){
        long long int count;
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
    }
void *countB(){
        long long int count;
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
    }
void *countC(){
        long long int count;
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
    }
    
int main (){
    FILE *f, *o, *r;
    f = fopen("fifo_sched.txt", "w");
    o = fopen("other_sched.txt", "w");
    r = fopen("rr_sched.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        struct timespec ini, end;
    clock_gettime(CLOCK_REALTIME, &ini);

    //1st part
    int which = PRIO_PROCESS;
    pthread_t t;
    pid_t t1 = pthread_self();
    id_t t11= getpid();
    setpriority(which, t11,i);
    pthread_create(&t,NULL,&countA,NULL);
    sched_setscheduler(t1,SCHED_OTHER,NULL);
    pthread_join(t, NULL);

    clock_gettime(CLOCK_REALTIME, &end);
    long long int val = end.tv_sec - ini.tv_sec ;
    char wr1[50];
    sprintf(wr1,"%d\n",val);
    fputs(wr1, o);

    //2nd part
    clock_gettime(CLOCK_REALTIME, &ini);

    int which1 = PRIO_PROCESS;
    pthread_t t2;
    pid_t t22 = pthread_self();
    id_t t222= getpid();
    setpriority(which1, t222,i);
    

    int valu2 = getpriority(which1, t222);
    printf("%d",valu2);


    pthread_create(&t2,NULL,&countB,NULL);
    sched_setscheduler(t22,SCHED_RR,NULL);
    pthread_join(t2, NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    long long int val1 = end.tv_sec - ini.tv_sec ;
    char wr2[50];
    
    sprintf(wr2,"%d\n",val1);
    fputs(wr2, r);
    
    clock_gettime(CLOCK_REALTIME, &ini);

    int which2 = PRIO_PROCESS;
    pthread_t t3;
    pid_t t33 = pthread_self();
    id_t t333= getpid();
    setpriority(which2, t333,i);
    int tempu = getpriority(which2,t333);
    printf("%d",tempu);
    
    pthread_create(&t3,NULL,&countC,NULL);
    sched_setscheduler(t33,SCHED_FIFO,NULL);
    pthread_join(t3, NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    long long int val2 = end.tv_sec - ini.tv_sec ;
    char wr3[50];
    
    sprintf(wr3,"%d\n",val2);
    fputs(wr3, f);
    }
}

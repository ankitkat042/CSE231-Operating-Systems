#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){

    struct timespec startA, endA;
    struct timespec startB, endB;
    struct timespec startC, endC;

    char *args[] = {"buffer", NULL};

    char *script = "linux-6.0.9/compile.sh";
    char *script2 = "linux-6.0.9.1/compile.sh";
    char *script3 = "linux-6.0.9.2/compile.sh";
    
    pid_t pid1 = fork();
    sched_setscheduler(pid1,SCHED_FIFO,NULL);
    setpriority(PRIO_PROCESS, pid1,0);
    if(pid1 == 0){
        clock_gettime(CLOCK_REALTIME, &startA);
        execvp(script, args);
        return 0;
    }
    else{
        
        pid_t pid2 = fork();
        sched_setscheduler(pid2,SCHED_FIFO,NULL);
        setpriority(PRIO_PROCESS, pid2,1);
        if(pid2 == 0){
            clock_gettime(CLOCK_REALTIME, &startB);
            execvp(script, args);
            return 0;
        }
        else{
            pid_t pid3 = fork();
            sched_setscheduler(pid3,SCHED_FIFO,NULL);
            setpriority(PRIO_PROCESS, pid3,2);
            if(pid3 == 0){
                clock_gettime(CLOCK_REALTIME, &startC);
                execvp(script, args);
                return 0;

            }
            else{
                clock_gettime(CLOCK_REALTIME, &endC);
                waitpid(pid3, NULL, 0);

            }
            waitpid(pid2, NULL, 0);
            clock_gettime(CLOCK_REALTIME, &endB);

        }
        waitpid(pid1, NULL, 0);
        clock_gettime(CLOCK_REALTIME, &endA);

    }
    double result1 = (endA.tv_sec - startA.tv_sec) + (endA.tv_nsec - startA.tv_nsec) / 1000000000.0;
    double result2 = (endB.tv_sec - startB.tv_sec) + (endB.tv_nsec - startB.tv_nsec) / 1000000000.0;
    double result3 = (endC.tv_sec - startC.tv_sec) + (endC.tv_nsec - startC.tv_nsec) / 1000000000.0;

    printf("time 1 end at %lf\n", result1);
    printf("time 2 end at %lf\n", result2);
    printf("time 3 end at %lf\n", result3);
}
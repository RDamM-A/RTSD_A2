#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <math.h>
#include <stdio.h>

#define BILLION  1000000000L;


void *myloop( void *ptr );

int main()
{
     pthread_t mythread;
    int a;
    int mask;
    struct timespec start, stop;
    double accum;
   //  int timer_create();

    sigset_t myalrm;
    sigemptyset(&myalrm);
    sigaddset(&myalrm, SIGALRM);
   // printf("%d\n",&myset);
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
    perror( "clock gettime" );
    }

    mask = pthread_sigmask(SIG_BLOCK, &myalrm, NULL); 
    a = pthread_create( &mythread, NULL, myloop, NULL);
    printf("%d\n",a);

    pthread_join( mythread, NULL);

    printf("%d\n",a);
    
    if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
    perror( "clock gettime" );
    }


    accum = ( stop.tv_sec - start.tv_sec )
            + (double)( stop.tv_nsec - start.tv_nsec )
            / (double)BILLION;
    printf( "%lf\n", accum );
    exit(0);
}

void *myloop( void *ptr )
{
    int count = 0;
    int mysig, ret_val;
    int *mysigptr = &mysig;
     timer_t mytimer_id;
    sigset_t myset;
    sigemptyset(&myset);
    sigaddset(&myset, SIGALRM);

    //sigset_t myset = void *ptr;
    struct sigevent myevent;
    myevent.sigev_notify = SIGEV_SIGNAL;
    myevent.sigev_signo = SIGALRM;



    struct itimerspec it;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_nsec = 1000000;
    it.it_value.tv_sec = it.it_interval.tv_sec;
    it.it_value.tv_nsec = it.it_interval.tv_nsec;
    //printf("%lf\n",(double) it.it_interval.tv_nsec);

    


    if(timer_create(CLOCK_REALTIME, &myevent, &mytimer_id) == -1 ) {
        perror( "timer_create" );
        }   

   
    void pthread_exit(void *retval);
    while (count < 5000)
    { 
    float res1= atan(tan(atan(tan(sqrt(3.1416/1)))));
    float res2= atan(tan(atan(tan(sqrt(3.1416/2)))));
    float res3= atan(tan(atan(tan(sqrt(3.1416/3)))));
    float res4= atan(tan(atan(tan(sqrt(3.1416/4)))));
    float res5= atan(tan(atan(tan(sqrt(3.1416/5)))));
    float res6= atan(tan(atan(tan(sqrt(3.1416/6)))));
    float res7= atan(tan(atan(tan(sqrt(3.1416/7)))));
    float res8= atan(tan(atan(tan(sqrt(3.1416/8)))));
    float res9= atan(tan(atan(tan(sqrt(3.1416/9)))));
    float res10= atan(tan(atan(tan(sqrt(3.1416/10)))));
    float res11= atan(tan(atan(tan(sqrt(3.1416/11)))));
    float res12= atan(tan(atan(tan(sqrt(3.1416/12)))));
    float res13= atan(tan(atan(tan(sqrt(3.1416/13)))));
    float res14= atan(tan(atan(tan(sqrt(3.1416/14)))));
    float res15= atan(tan(atan(tan(sqrt(3.1416/15)))));
    
    if(timer_settime(mytimer_id,0, &it, NULL) == -1 ) {
         perror( "timer_settime" );
      }

    ret_val = sigwait(&myset,&mysig);
    count++;
    }

pthread_exit;
    }



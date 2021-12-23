#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define BILLION  1000000000L;

void *myloop( void *ptr );

int main()
{
     pthread_t mythread;
    int a;
    struct timespec start, stop;
    double accum;


    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
    perror( "clock gettime" );
    }

    a = pthread_create( &mythread, NULL, myloop, (void*) NULL);
    pthread_join( mythread, NULL);

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
    long s;
    long ns;
    void pthread_exit(void *retval);
    struct timespec tp;
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
    
    if (clock_gettime(CLOCK_REALTIME, &tp) == -1) {
        perror("monotonic_clock");
    };
    //printf( "%lf and %lf\n  ", (double) tp.tv_sec, (double) tp.tv_nsec);
    if(tp.tv_nsec>=999000000L){
         s = tp.tv_sec +1;
         ns = tp.tv_nsec-999000000L;
    }
    else{
        s = tp.tv_sec;
        ns = tp.tv_nsec + 1000000L;
    }
    clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME,(const struct timespec[]){{s,ns}},NULL);
    //nanosleep((const struct timespec[]){{0, 1000000L}}, NULL);
    count++;
    __real_printf("%d\n", count );
    }
//sleep(60);
pthread_exit;
}



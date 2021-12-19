#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BILLION  1000000000L;

void *myloop( void *ptr );

int main()
{
     pthread_t mythread;
    int a;

    /* Create independent threads each of which will execute function */

    a = pthread_create( &mythread, NULL, myloop, (void*) NULL);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( mythread, NULL);


     printf("Thread 1 returns: %d\n",a);
     exit(0);
}

void *myloop( void *ptr )
{
    struct timespec start, stop;
    double accum;
    int count = 0;
    void pthread_exit(void *retval);
    while (count < 1000)
    {  
        

        if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
        perror( "clock gettime" );
        pthread_exit;
        }

        nanosleep((const struct timespec[]){{0, 1000000L}}, NULL);

        if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
        perror( "clock gettime" );
        pthread_exit;
        }


        accum = ( stop.tv_sec - start.tv_sec )
                + (double)( stop.tv_nsec - start.tv_nsec )
                / (double)BILLION;
        //printf( "%lf\n", accum );
        count++;
    }
    

}



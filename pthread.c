#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define NUM_THREADS 5

/*线程函数*/
void *print_hello(void *threadid)
{
	long tid;
	tid = (long)threadid;

	/*打印线程对应的参数*/
	printf("Hello World! It's me, thread #%ld\n", tid);

	/*子线程退出*/
	pthread_exit(NULL);
}

/*
int pthread_create(pthread_t *restrict tidp,
                   const pthread_attr_t *restrict attr,
                   void *(*start_rtn)(void), 
                   void *restrict arg);
*/
int main(int argc, char *argv[NUM_THREADS])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	/*创建5个线程*/
	for(t = 0; t < NUM_THREADS; t++) {
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
		if(rc) {
			printf("ERROR: return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	printf("In main: exit!\n");

	/*主线程退出*/
	pthread_exit(NULL);
	return 0;
}





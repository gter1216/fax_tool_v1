
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define NUM_CALLS 5
#define NUM_THREADS 5

void initial(int num_calls)
{

}

void * say_hello(void *threadid)
{
	int tid = *((int*)threadid);
	sleep(5);
	printf("Hello Charles! Thread ID is %d!\n", tid);
	//pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int indexes[NUM_THREADS];
	int result;
	int i;

	initial(NUM_CALLS);

	for (i = 0; i < NUM_THREADS; ++i)
	{
		printf("create thread %d\n", i);
		indexes[i] = i;
		result = pthread_create(&threads[i], NULL, 
			say_hello, (void *)&(indexes[i]));
		
		if (result != 0)
		{
			printf("Thread create error!\n");
			exit(-1);
		}
	}
	// 如果不加这句话，假设很快5个线程都创建完毕了，main函数退出，进程结束，所有的线程也结束，
	// 所以必须要加这句话
	pthread_exit(NULL);
}

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
	// ���������仰������ܿ�5���̶߳���������ˣ�main�����˳������̽��������е��߳�Ҳ������
	// ���Ա���Ҫ����仰
	pthread_exit(NULL);
}
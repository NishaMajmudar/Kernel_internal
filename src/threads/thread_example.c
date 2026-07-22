#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg){
	printf("Thread is running\n");
	return NULL;
}

int main(){
	pthread_t tid;
	pthread_create(&tid, NULL, thread_func, NULL);
	pthread_join(tid,NULL);
	return 0;
}

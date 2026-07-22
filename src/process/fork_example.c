#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid = fork();

	if(pid == 0){
		printf("Child process: PID = %d\n",getpid());
	}
	else{
		printf("Parent Process: PID = %d, Child PID = %d\n",getpid(), pid);
	}
}

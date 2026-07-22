#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pipe(fd);

	if(fork()==0){
		close(fd[0]);
		char msg[] = "Child process enters";
		write(fd[1], msg, strlen(msg)+1);
	}
	else{
		close(fd[1]);
		char buffer[50];
		read(fd[0], buffer, sizeof(buffer));
		printf("Parent received: %s\n",buffer);
	}
	return 0;
}

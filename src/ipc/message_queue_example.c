#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
	long msg_type;
	char msg_text[100];
};

int main(){
	key_t key = ftok("pprogfile",65);
	int msgid = msgget(key, 0666 | IPC_CREAT);

	struct msg_buffer message;
	message.msg_type = 1;
	strcpy(message.msg_text, "Queue message!!");

	msgsnd(msgid, &message, sizeof(message),0);
	msgrcv(msgid, &message, sizeof(message),1,0);

	printf("Received: %s\n",message.msg_text);
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}

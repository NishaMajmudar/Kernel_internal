#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, NULL, 0);

    strcpy(str, "Hello Shared Memory");
    printf("Data written: %s\n", str);

    printf("Data read: %s\n", str);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

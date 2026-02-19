/* Q1: Sender - Send a number to Process B via Message Queue */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    int num;
} message;

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;

    printf("Enter a number to send: ");
    scanf("%d", &message.num);

    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Number %d sent.\n", message.num);

    return 0;
}
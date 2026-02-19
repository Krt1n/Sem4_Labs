/* Q1: Receiver - Check if received number is Palindrome */
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

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    
    int n = message.num, rev = 0, rem, temp = n;
    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    if (n == rev) printf("Number %d is a Palindrome.\n", n);
    else printf("Number %d is NOT a Palindrome.\n", n);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
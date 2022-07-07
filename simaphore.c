#include<stdio.h>
#include<sys/sem.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>

int semget(key_t key,int nsems,int semflg);
int main(){
int semid,shmid,msgid,key;
key=(key_t)0X40;
semid=semget(key,1,0666|IPC_CREAT);
shmid=shmget(key,1024,0666|IPC_CREAT);
msgid=msgget(key,0666|IPC_CREAT);
if(msgid==-1)
{
perror("msgget");
exit(1);
}
if(shmid==-1)
{
perror("shmget");
exit(1);
}
if(semid==-1)
{
perror("semget");
exit(1);
}
printf("semid= %d\nshmid= %d\nmsgid= %d\n",semid,shmid,msgid);
return 0;
}


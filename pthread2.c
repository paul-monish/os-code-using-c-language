#include<stdio.h>
#include<pthread.h>

void* print_msg(void*);

int main(){
pthread_t t1,t2;
int r1,r2;
char *m1="thread1",*m2="thread2";
r1=pthread_create(&t1,NULL,print_msg,m1);
r2=pthread_create(&t2,NULL,print_msg,m2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("t1= %d\n t2= %d\n",r1,r2);
return 0;
}

void* print_msg(void *ptr){
char *msg;
msg=(char*)ptr;
printf("%s\n",msg);
}

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void inthandler(int sig_no);
void quithandler(int sig_no);
void huphandler(int sig_no);

int main(){
int pid;
if((pid=fork())<0){
perror("child not created");
exit(1);
}
if(pid==0){
signal(SIGINT,inthandler);
signal(SIGQUIT,quithandler);
signal(SIGHUP,huphandler);
for(;;);
}
else{
printf("pid= %d\n",pid);

printf("sending SIGINT signal\n");
kill(pid,SIGINT);
sleep(5);

printf("sending SIGQUIT signal\n");
kill(pid,SIGQUIT);
sleep(5);

printf("sending SIGHUP signal\n");
kill(pid,SIGHUP);
sleep(5);

printf("sending SIGSTOP signal\n");
kill(pid,SIGSTOP);
sleep(5);
}
return 0;
}

void inthandler(int sig_no){
signal(SIGINT,inthandler);
printf("interrupt signal handel by child\n");
}
void quithandler(int sig_no){
signal(SIGQUIT,quithandler);
printf("quit signal handel by child\n");
}
void huphandler(int sig_no){
signal(SIGHUP,huphandler);
printf("hang up signal handel by child\n");
}


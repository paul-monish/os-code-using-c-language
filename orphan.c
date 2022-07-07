 //orphan process//
#include<stdio.h>
#include<unistd.h>

int main(){
int pid;
pid=fork();
if(pid==0){
printf("child and pid=%d",getpid());
printf("child and parent pid=%d",getppid());
sleep(5);
printf("child and pid=%d",getpid());
printf("child and parent pid=%d",getppid());
}
else if(pid>0){
printf("parent and pid=%d",getpid());
printf("parent and parent pid=%d",getppid());
}
else{
printf("unsuccessfull execution");
}
return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
int pid,fd;
if((pid=fork())<0){
printf("fork faild");
exit(1);
}

if(mknod("mypipe",010600,0)<0)
perror("could not create named pipe");


if(pid==0){
int j=0,k=2;
if((fd=open("mypipe",O_WRONLY))<0){
printf("faild to open");
exit(2);
}
for(j=0;j<10;j++){
write(fd,&k,sizeof(k));
k=2*k+1;
}
}
else{
int k,j=0;
sleep(1);
if((fd=open("mypipe",O_RDONLY))<0){
printf("unable to open");
exit(2);
}
for(j=0;j<10;j++){
read(fd,&k,sizeof(k));
printf("%d\n",k);
}
}

return 0;
}


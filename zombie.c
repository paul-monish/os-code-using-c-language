//zombie process//
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
if(fork()>0){
printf("parent");
sleep(20);
}
else if(fork()==0){
printf("Zombi %d",getpid());
exit(0);
}
return 0;
}

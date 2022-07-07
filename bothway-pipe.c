#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char p1w[20]="hii";
char p2w[20]="hello";
char r[20];
int p1[2],p2[2],ret1,ret2,pid;
ret1=pipe(p1);
if(ret1==-1){
printf("unable to create pipe1\n");
exit(1);
}
ret2=pipe(p2);
if(ret2==-1){
printf("unable to create pipe2\n");
exit(1);
}

pid=fork();
if(pid!=0){
close(p1[0]);
close(p2[1]);
printf("parent write to pipe1 -m1 %s\n",p1w);
write(p1[1],p1w,sizeof(p1w));
read(p2[0],r,sizeof(r));
printf("parent read from pipe2 -m2 %s\n",r);
}
else{
close(p1[1]);
close(p2[0]);
read(p1[0],r,sizeof(r));
printf("child read from pipe1 -m1 %s\n",r);
printf("child write to pipe2 -m2 %s\n",r);
write(p2[1],p2w,sizeof(p2w));
}

return 0;
}

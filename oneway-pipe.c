#include<stdio.h>
#include<unistd.h>

int main(){
char w[2][20]={"hii","hello"};
char r[20];
int p[2],ret,pid,rnice;
ret=pipe(p);
if(ret==-1){
printf("unable to create pipe\n");
return 1;
}
pid=fork();
if(pid==0){
rnice=nice(5);
read(p[0],r,sizeof(r));
printf("child reading from pipe m1 %s\n",r);
read(p[0],r,sizeof(r));
printf("child reading from pipe m2 %s\n",r);
}
else{
rnice=nice(-4);
printf("parent writing to pipe -m1 %s\n",w[0]);
write(p[1],w[0],sizeof(w[0]));
printf("parent writing to pipe -m2 %s\n",w[1]);
write(p[1],w[1],sizeof(w[1]));
}

return 0;
}

#include<stdio.h>
#include<unistd.h>

int main(){
int p[2];
pipe(p);
printf("read pipe= %d\n write pipe= %d",p[0],p[1]);
return 0;
}

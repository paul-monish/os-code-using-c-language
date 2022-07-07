#include<stdio.h>
#include<pthread.h>

void* addition_n(void*);

int main(){
pthread_t t1,t2;
int r1,r2,n;
int *ptr;
printf("Enter Number:");
scanf("%d",&n);
ptr=&n;
r1=pthread_create(&t1,NULL,addition_n,ptr);
r2=pthread_create(&t2,NULL,addition_n,ptr);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("t1= %d\n t2= %d\n",r1,r2);
return 0;
}

void* addition_n(void *ptr){
int *n;
int i,s=0;
n=(int*)ptr;
//for(i=1;i<=*n;i++)
	//s+=i;
s=(*n*(*n+1))/2;
printf("sum= %d",s);
}
